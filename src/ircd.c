/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/**
 * @file ircd.c
 * @brief Starts up and runs the ircd.
 *
 * This file contains the main entry point and functionality for starting up
 * and running the ircd (Internet Relay Chat Daemon). It initializes various
 * components, sets up event handlers, and manages server configurations.
 */

#include "stdinc.h"
#include "io_getopt.h"
#include "io_pidfile.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"
#include "irc_string.h"
#include "event.h"
#include "fdlist.h"
#include "comm.h"
#include "log.h"
#include "res.h"
#include "rng_mt.h"
#include "defaults.h"
#include "user.h"
#include "ircd.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "cloak.h"
#include "hash.h"
#include "id.h"
#include "ircd_signal.h"
#include "motd.h"
#include "conf.h"
#include "parse.h"
#include "server.h"
#include "server_capab.h"
#include "send.h"
#include "module.h"
#include "conf_db.h"
#include "conf_class.h"
#include "ipcache.h"
#include "isupport.h"
#include "extban.h"
#include "ircd_exit.h"
#include "flatten_links.h"

/**
 * @struct SetOptions
 * @brief Structure for server configuration options.
 *
 * The `SetOptions` structure holds various options related to server configuration,
 * allowing modification through the SET irc command. It includes flags and settings
 * for features such as auto connection, maximum clients, and flood control.
 */
struct SetOptions GlobalSetOptions;

/**
 * @struct Counter
 * @brief Structure holding various server activity counters.
 *
 * The `Counter` structure tracks various server activity metrics, including total
 * client connections, IRC operator count, invisible clients, and peak client counts.
 */
struct Counter Count;

/**
 * @struct ServerState_t
 * @brief Structure representing the server's foreground state.
 *
 * The `ServerState_t` structure holds a flag indicating whether the server should
 * run in the foreground. The flag is set based on the command line parameter
 * '-foreground' when launching the ircd process.
 */
struct ServerState_t server_state;

/**
 * @struct ServerStatistics
 * @brief Structure for server communication and connection statistics.
 *
 * The `ServerStatistics` structure contains statistics related to server communication
 * and connections. These metrics provide insights into data transmission, connection
 * durations, and various activities between clients and servers.
 */
struct ServerStatistics ServerStats;

/**
 * @struct Connection
 * @brief Structure representing the connection details for this server.
 *
 * The `Connection` structure encapsulates the connection details for the server,
 * including information such as connection status, socket details, and connection settings.
 */
static struct Connection meConnection;

/**
 * @struct Client
 * @brief Structure representing the client details for this server.
 *
 * The `Client` structure represents the client details for the server, with a connection
 * link pointing to the associated `Connection` structure. This structure provides a
 * comprehensive view of the client's attributes within the context of the server.
 */
struct Client me = { .connection = &meConnection };

/**
 * @var char **myargv
 * @brief Pointer to the command line arguments.
 */
char **myargv;

/**
 * @var const char *logFileName
 * @brief Pointer to the filename for the ircd.log file.
 */
const char *logFileName = LPATH;

/**
 * @var const char *pidFileName
 * @brief Pointer to the filename for the process ID file.
 */
const char *pidFileName = PPATH;

/**
 * @var bool printVersion
 * @brief Flag indicating whether to print the version and exit.
 */
static bool printVersion;

/**
 * @var struct io_getopt myopts[]
 * @brief Array of command-line options and their descriptions.
 */
static struct io_getopt myopts[] =
{
  { "configfile", 'c', &ConfigGeneral.configfile, STRING, "File to use for ircd.conf" },
  { "klinefile", 'k', &ConfigGeneral.klinefile, STRING, "File to use for kline database" },
  { "dlinefile", 'd', &ConfigGeneral.dlinefile, STRING, "File to use for dline database" },
  { "xlinefile", 'x', &ConfigGeneral.xlinefile, STRING, "File to use for xline database" },
  { "resvfile", 'r', &ConfigGeneral.resvfile, STRING, "File to use for resv database" },
  { "logfile", 'l', &logFileName, STRING, "File to use for ircd.log" },
  { "pidfile", 'p', &pidFileName, STRING, "File to use for process ID" },
  { "foreground", 'f', &server_state.foreground, BOOLEAN, "Run in foreground (don't detach)" },
  { "version", 'v', &printVersion, BOOLEAN, "Print version and exit" },
  { "help", 'h', NULL, USAGE, "Print this text" },
  { NULL, 0, NULL, STRING, NULL }
};

static struct event event_cleanup_tklines =
{
  .name = "cleanup_tklines",
  .handler = cleanup_tklines,
  .when = 30
};

static struct event event_server_connect_auto =
{
  .name = "server_connect_auto",
  .handler = server_connect_auto,
  .when = 15
};

static struct event event_comm_checktimeouts =
{
  .name = "comm_checktimeouts",
  .handler = comm_checktimeouts,
  .when = 1
};

static struct event event_save_all_databases =
{
  .name = "save_all_databases",
  .handler = save_all_databases,
  .when = 300
};

/**
 * @brief Main IO loop for processing events and managing server activities.
 *
 * This function runs continuously, handling various tasks such as
 * processing events, checking for rehash signals, and managing client connections.
 */
static void
io_loop(void)
{
  while (true)
  {
    if (listing_client_list.head)
    {
      list_node_t *node, *node_next;
      LIST_FOREACH_SAFE(node, node_next, listing_client_list.head)
        safe_list_channels(node->data, false);
    }

    /* Run pending events */
    event_run();

    comm_select();
    exit_aborted_clients();
    free_exited_clients();

    /* Check to see whether we have to rehash the configuration. */
    if (dorehash)
    {
      conf_rehash(true);
      dorehash = 0;
    }

    if (doremotd)
    {
      motd_recache();
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "Got signal SIGUSR1, reloading motd file(s)");
      doremotd = 0;
    }
  }
}

/**
 * @brief Initializes global server configuration options.
 *
 * This function sets default values for various global server configuration options
 * needed during runtime. It is responsible for initializing the `GlobalSetOptions`
 * structure, which holds key settings that can be modified using the SET irc command.
 */
static void
initialize_global_set_options(void)
{
  GlobalSetOptions.maxclients = ConfigServerInfo.default_max_clients;
  GlobalSetOptions.autoconnect = true;
  GlobalSetOptions.spam_time = MIN_JOIN_LEAVE_TIME;
  GlobalSetOptions.spam_num = MAX_JOIN_LEAVE_COUNT;
  GlobalSetOptions.floodcount = ConfigGeneral.default_floodcount;
  GlobalSetOptions.floodtime = ConfigGeneral.default_floodtime;
  GlobalSetOptions.joinfloodcount = ConfigChannel.default_join_flood_count;
  GlobalSetOptions.joinfloodtime = ConfigChannel.default_join_flood_time;
}

/**
 * @brief Handles out-of-memory conditions.
 *
 * This function reports an out-of-memory condition and restarts the program.
 */
static void
ircd_oom(void)
{
  ircd_exit("out of memory", IRCD_EXIT_RESTART);
}

/**
 * @brief Handles time provider API error conditions.
 *
 * This function reports an error condition encountered in the time provider API using the provided
 * error message. It exits with EXIT_FAILURE if the error code is IO_TIME_ERR_INIT, otherwise, it restarts the program.
 *
 * @param error_code The error code indicating the type of error in the time provider API.
 * @param message The error message providing details about the time provider API error.
 */
static void
ircd_time_failure(enum io_time_error_code error_code, const char *message)
{
  if (error_code == IO_TIME_ERR_INIT)
  {
    fprintf(stderr, "ERROR: %s\n", message);
    exit(EXIT_FAILURE);  /* Exit with failure if initialization error. */
  }

  ircd_exit(message, IRCD_EXIT_RESTART);  /* Restart the program for other errors. */
}

/**
 * @brief Sets up the core file size to system limits.
 *
 * This function sets the core file size to the maximum allowed by the system.
 */
static void
setup_corefile(void)
{
  struct rlimit rlim; /* resource limits */

  /* Set corefilesize to maximum */
  if (getrlimit(RLIMIT_CORE, &rlim) == 0)
  {
    rlim.rlim_cur = rlim.rlim_max;
    setrlimit(RLIMIT_CORE, &rlim);
  }
}

/**
 * @brief Sets up the maximum number of file descriptors.
 *
 * This function sets up the maximum number of file descriptors that
 * the ircd server is allowed to use.
 */
static void
setup_fdlimit(void)
{
  struct rlimit rlim;

  if (getrlimit(RLIMIT_NOFILE, &rlim))
  {
    fprintf(stderr, "getrlimit: couldn't get maximum number of file descriptors: %s\n",
            strerror(errno));
    exit(EXIT_FAILURE);
  }

#ifdef __APPLE__
  if (rlim.rlim_max > OPEN_MAX)
    rlim.rlim_max = OPEN_MAX;
#endif
  if (rlim.rlim_max > 0xFFFF)
    rlim.rlim_max = 0xFFFF;
  rlim.rlim_cur = rlim.rlim_max;

  if (setrlimit(RLIMIT_NOFILE, &rlim))
  {
    fprintf(stderr, "setrlimit: couldn't set maximum number of file descriptors: %s\n",
            strerror(errno));
    exit(EXIT_FAILURE);
  }

  hard_fdlimit = rlim.rlim_cur;
}

/**
 * @brief Prints startup information including version and process ID.
 *
 * This function prints information about the server version, process ID,
 * and whether it is running in the background or foreground.
 *
 * @param pid Process ID of the ircd server.
 */
static void
print_startup(int pid)
{
  printf("ircd: version %s\n", IRCD_VERSION);
  printf("ircd: pid %d\n", pid);
  printf("ircd: running in %s mode from %s\n",
         server_state.foreground ? "foreground": "background", ConfigGeneral.dpath);
}

/**
 * @brief Transforms the current process into a daemon for background execution.
 *
 * This function creates a child process using fork(), allowing the parent process
 * to exit. The child becomes a daemon by detaching from the terminal and setting
 * up a new session using setsid(). Standard input, output, and error are redirected
 * to /dev/null to isolate the daemon from the terminal.
 */
static void
make_daemon(void)
{
  int pid = fork();
  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid > 0)
  {
    print_startup(pid);
    exit(EXIT_SUCCESS);
  }

  if (setsid() == -1)
  {
    perror("setsid");
    exit(EXIT_FAILURE);
  }

  /* Connect stdin, stdout, and stderr to /dev/null */
  int fd = open("/dev/null", O_RDWR);
  if (fd == -1)
  {
    perror("open");
    exit(EXIT_FAILURE);
  }

  dup2(fd, STDIN_FILENO);
  dup2(fd, STDOUT_FILENO);
  dup2(fd, STDERR_FILENO);

  if (fd > STDERR_FILENO)
    close(fd);
}

/**
 * @brief Main function to initialize and run the IRC server.
 *
 * This is the main entry point for the ircd server. It initializes various
 * components, sets up signal handling, reads configuration files, and runs
 * the main IO loop to handle server activities.
 *
 * @param argc Number of command line arguments.
 * @param argv Array of command line argument strings.
 * @return Returns 0 upon successful execution.
 */
int
main(int argc, char *argv[])
{
  /* Check to see if the user is running us as root, which is a nono */
  if (geteuid() == 0)
  {
    fprintf(stderr, "ERROR: This server won't run as root/superuser\n");
    return -1;
  }

  io_set_oom_handler(ircd_oom);

  /* Setup corefile size immediately after boot -kre */
  setup_corefile();

  setup_fdlimit();

  /* Save server boot time right away, so getrusage works correctly */
  io_time_set_error_callback(ircd_time_failure);
  io_time_init();

  /*
   * Calculate the seed using multiple sources of entropy
   * - Real-time and monotonic clocks provide high-resolution time values
   * - Process ID adds process-specific uniqueness
   * This combination aims to create a seed that is harder to predict
   */
  const uint32_t seed = (uint32_t)(
     (io_time_get(IO_TIME_REALTIME_SEC) % UINT32_MAX) ^  /* Real-time seconds (modulo to fit in 32 bits) */
      io_time_get(IO_TIME_REALTIME_NSEC) ^  /* Real-time nanoseconds */
    ((io_time_get(IO_TIME_MONOTONIC_SEC) % UINT32_MAX) ^  /* Monotonic seconds (modulo to fit in 32 bits) */
      io_time_get(IO_TIME_MONOTONIC_NSEC) ^  /* Monotonic nanoseconds */
    ((uint32_t)(getpid() & 0xFFFF) << 16))  /* Masked and shifted PID for added entropy */
  );

  init_genrand(seed);

  ConfigGeneral.dpath      = DPATH;
  ConfigGeneral.spath      = SPATH;
  ConfigGeneral.configfile = CPATH;    /* Server configuration file */
  ConfigGeneral.klinefile  = KPATH;    /* Server kline file         */
  ConfigGeneral.xlinefile  = XPATH;    /* Server xline file         */
  ConfigGeneral.dlinefile  = DLPATH;   /* dline file                */
  ConfigGeneral.resvfile   = RESVPATH; /* resv file                 */

  myargv = argv;
  umask(077);  /* umask 077: u=rwx,g=,o= */

  io_getopt(&argc, &argv, myopts);

  if (printVersion)
  {
    printf("ircd: version %s\n", IRCD_VERSION);
    exit(EXIT_SUCCESS);
  }

  if (chdir(ConfigGeneral.dpath))
  {
    perror("chdir");
    exit(EXIT_FAILURE);
  }

  if (server_state.foreground)
    print_startup(getpid());
  else
    make_daemon();

  ircd_signal_init();

  /* We need this to initialise the fd array before anything else */
  fdlist_init();
  log_add(LOG_TYPE_IRCD, true, 0, logFileName);

  comm_select_init();  /* This needs to be setup early ! -- adrian */
  tls_init();

  /* Check if there is pidfile and daemon already running */
  if (io_pidfile_create(pidFileName))
    exit(EXIT_FAILURE);

  isupport_init();
  ipcache_init();
  client_init();
  class_init();
  cloak_init();
  resolver_init();      /* Needs to be setup before the io loop */
  module_init();
  conf_read_files(true);   /* cold start init conf files */
  channel_mode_init();
  extban_init();
  capab_init();  /* Set up default_server_capabs */
  initialize_global_set_options();  /* Has to be called after conf_read_files() */
  user_modes_init();
  flatten_links_init();

  if (EmptyString(ConfigServerInfo.name))
  {
    log_write(LOG_TYPE_IRCD, "ERROR: No server name specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.name, ConfigServerInfo.name, sizeof(me.name));

  /* serverinfo {} description must exist.  If not, error out.*/
  if (EmptyString(ConfigServerInfo.description))
  {
    log_write(LOG_TYPE_IRCD, "ERROR: No server description specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));

  if (EmptyString(ConfigServerInfo.sid))
  {
    log_write(LOG_TYPE_IRCD, "Generating server ID");
    generate_sid();
    ConfigServerInfo.sid = io_strdup(me.id);
  }
  else
    strlcpy(me.id, ConfigServerInfo.sid, sizeof(me.id));

  init_uid();

  me.from = &me;
  me.servptr = &me;
  me.connection->created_real = io_time_get(IO_TIME_REALTIME_SEC);
  me.connection->created_monotonic = io_time_get(IO_TIME_MONOTONIC_SEC);

  SetMe(&me);
  server_make(&me);

  hash_add_id(&me);
  hash_add_client(&me);

  list_add(&me, &me.node, &global_server_list);

  load_kline_database(ConfigGeneral.klinefile);
  load_dline_database(ConfigGeneral.dlinefile);
  load_xline_database(ConfigGeneral.xlinefile);
  load_resv_database(ConfigGeneral.resvfile);

  module_load_all(NULL);

  event_addish(&event_cleanup_tklines, NULL);

  /* We want server_connect_auto to be called as soon as possible now! -- adrian */
  /* No, 'cause after a restart it would cause all sorts of nick collides */
  event_addish(&event_server_connect_auto, NULL);

  /* Setup the timeout check. I'll shift it later :)  -- adrian */
  event_add(&event_comm_checktimeouts, NULL);

  event_addish(&event_save_all_databases, NULL);

  log_write(LOG_TYPE_IRCD, "Server ready. Running version: %s", IRCD_VERSION);
  io_loop();

  return 0;
}
