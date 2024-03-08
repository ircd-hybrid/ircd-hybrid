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
#include "user.h"
#include "list.h"
#include "ircd.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "event.h"
#include "fdlist.h"
#include "hash.h"
#include "id.h"
#include "irc_string.h"
#include "ircd_signal.h"
#include "memory.h"
#include "motd.h"
#include "conf.h"
#include "hostmask.h"
#include "parse.h"
#include "res.h"
#include "rng_mt.h"
#include "s_bsd.h"
#include "log.h"
#include "server.h"
#include "server_capab.h"
#include "send.h"
#include "modules.h"
#include "ircd_getopt.h"
#include "conf_db.h"
#include "conf_class.h"
#include "ipcache.h"
#include "isupport.h"
#include "extban.h"

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
 * @var bool dorehash
 * @brief Flag indicating whether to reload ircd configuration files.
 *
 * This flag is set to true when the ircd receives a SIGHUP signal,
 * indicating the need to reload the configuration files.
 */
bool dorehash;

/**
 * @var bool doremotd
 * @brief Flag indicating whether to reload the Message of the Day (MOTD) files.
 *
 * This flag is set to true when the ircd receives a SIGUSR1 signal,
 * indicating the need to reload the MOTD files.
 */
bool doremotd;

/**
 * @var bool printVersion
 * @brief Flag indicating whether to print the version and exit.
 */
static bool printVersion;

/**
 * @var struct lgetopt myopts[]
 * @brief Array of command-line options and their descriptions.
 */
static struct lgetopt myopts[] =
{
  { "configfile", &ConfigGeneral.configfile,
   STRING, "File to use for ircd.conf" },
  { "klinefile",  &ConfigGeneral.klinefile,
   STRING, "File to use for kline database" },
  { "dlinefile",  &ConfigGeneral.dlinefile,
   STRING, "File to use for dline database" },
  { "xlinefile",  &ConfigGeneral.xlinefile,
   STRING, "File to use for xline database" },
  { "resvfile",   &ConfigGeneral.resvfile,
   STRING, "File to use for resv database" },
  { "logfile",    &logFileName,
   STRING, "File to use for ircd.log" },
  { "pidfile",    &pidFileName,
   STRING, "File to use for process ID" },
  { "foreground", &server_state.foreground,
   BOOLEAN, "Run in foreground (don't detach)" },
  { "version",    &printVersion,
   BOOLEAN, "Print version and exit" },
  { "help", NULL, USAGE, "Print this text" },
  { NULL, NULL, STRING, NULL },
};

static struct event event_cleanup_tklines =
{
  .name = "cleanup_tklines",
  .handler = cleanup_tklines,
  .when = CLEANUP_TKLINES_TIME
};

static struct event event_try_connections =
{
  .name = "try_connections",
  .handler = try_connections,
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
  .when = DATABASE_UPDATE_TIMEOUT
};

struct event event_write_links_file =
{
  .name = "write_links_file",
  .handler = write_links_file,
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
      dlink_node *node, *node_next;
      DLINK_FOREACH_SAFE(node, node_next, listing_client_list.head)
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
      dorehash = false;
    }

    if (doremotd)
    {
      motd_recache();
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "Got signal SIGUSR1, reloading motd file(s)");
      doremotd = false;
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
 * @brief Writes the process ID to the specified file.
 *
 * @param filename Path to the process ID file.
 *
 * This function opens the specified file and writes the process ID of
 * the ircd server to it.
 */
static void
write_pidfile(const char *filename)
{
  FILE *fb = fopen(filename, "w");

  if (fb)
  {
    char buf[IRCD_BUFSIZE];
    unsigned int pid = (unsigned int)getpid();

    snprintf(buf, sizeof(buf), "%u\n", pid);

    if (fputs(buf, fb) == -1)
      log_write(LOG_TYPE_IRCD, "Error writing to pid file %s: %s",
           filename, strerror(errno));

    fclose(fb);
  }
  else
    log_write(LOG_TYPE_IRCD, "Error opening pid file %s: %s",
         filename, strerror(errno));
}

/**
 * @brief Checks if the daemon is already running using the process ID file.
 *
 * This function reads the process ID from the specified file and checks
 * if the ircd server is already running. If it is, the program exits
 * to prevent multiple instances.
 *
 * @param filename Path to the process ID file.
 */
static void
check_pidfile(const char *filename)
{
  FILE *fb = fopen(filename, "r");

  if (fb)
  {
    char buf[IRCD_BUFSIZE]; 

    if (fgets(buf, 20, fb) == NULL)
      log_write(LOG_TYPE_IRCD, "Error reading from pid file %s: %s",
           filename, strerror(errno));
    else
    {
      pid_t pid = atoi(buf);

      if (kill(pid, 0) == 0)
      {
        /* log(L_ERROR, "Server is already running"); */
        printf("ircd: daemon is already running\n");
        exit(EXIT_FAILURE);
      }
    }

    fclose(fb);
  }
  else if (errno != ENOENT)
    log_write(LOG_TYPE_IRCD, "Error opening pid file %s: %s",
         filename, strerror(errno));
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
  printf("ircd: running in %s mode from %s\n", !server_state.foreground ? "background"
         : "foreground", ConfigGeneral.dpath);
}

/**
 * @brief Detaches the server process to run as a daemon.
 *
 * This function forks the process to create a child, detaches it from
 * the terminal, and runs it as a daemon in the background.
 */
static void
make_daemon(void)
{
  int pid = fork();

  if (pid < 0)
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
  if (fd < 0)
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

  /* Setup corefile size immediately after boot -kre */
  setup_corefile();

  setup_fdlimit();

  /* Save server boot time right away, so getrusage works correctly */
  event_time_set();

  /* It's not random, but it ought to be a little harder to guess */
  uint32_t seed = (uint32_t)(event_base->time.sec_real ^
                             (event_base->time.sec_monotonic | (getpid() << 16)));
  init_genrand(seed);

  ConfigGeneral.dpath      = DPATH;
  ConfigGeneral.spath      = SPATH;
  ConfigGeneral.mpath      = MPATH;
  ConfigGeneral.configfile = CPATH;    /* Server configuration file */
  ConfigGeneral.klinefile  = KPATH;    /* Server kline file         */
  ConfigGeneral.xlinefile  = XPATH;    /* Server xline file         */
  ConfigGeneral.dlinefile  = DLPATH;   /* dline file                */
  ConfigGeneral.resvfile   = RESVPATH; /* resv file                 */

  myargv = argv;
  umask(077);  /* umask 077: u=rwx,g=,o= */

  ircd_getopt(&argc, &argv, myopts);

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

  setup_signals();

  /* We need this to initialise the fd array before anything else */
  fdlist_init();
  log_add(LOG_TYPE_IRCD, true, 0, logFileName);

  comm_select_init();  /* This needs to be setup early ! -- adrian */
  tls_init();

  /* Check if there is pidfile and daemon already running */
  check_pidfile(pidFileName);

  isupport_init();
  ipcache_init();
  client_init();
  class_init();
  resolver_init();      /* Needs to be setup before the io loop */
  modules_init();
  conf_read_files(true);   /* cold start init conf files */
  channel_mode_init();
  extban_init();
  capab_init();  /* Set up default_server_capabs */
  initialize_global_set_options();  /* Has to be called after conf_read_files() */
  read_links_file();
  motd_init();
  user_modes_init();

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
    ConfigServerInfo.sid = xstrdup(me.id);
  }
  else
    strlcpy(me.id, ConfigServerInfo.sid, sizeof(me.id));

  init_uid();

  me.from = &me;
  me.servptr = &me;
  me.connection->created_real = event_base->time.sec_real;
  me.connection->created_monotonic = event_base->time.sec_monotonic;

  SetMe(&me);
  server_make(&me);

  hash_add_id(&me);
  hash_add_client(&me);

  dlinkAdd(&me, &me.node, &global_server_list);

  load_kline_database(ConfigGeneral.klinefile);
  load_dline_database(ConfigGeneral.dlinefile);
  load_xline_database(ConfigGeneral.xlinefile);
  load_resv_database(ConfigGeneral.resvfile);

  load_all_modules(true);
  load_conf_modules();
  load_core_modules(true);

  write_pidfile(pidFileName);

  event_addish(&event_cleanup_tklines, NULL);

  /* We want try_connections to be called as soon as possible now! -- adrian */
  /* No, 'cause after a restart it would cause all sorts of nick collides */
  event_addish(&event_try_connections, NULL);

  /* Setup the timeout check. I'll shift it later :)  -- adrian */
  event_add(&event_comm_checktimeouts, NULL);

  event_addish(&event_save_all_databases, NULL);

  if (ConfigServerHide.flatten_links_delay && event_write_links_file.active == false)
  {
    event_write_links_file.when = ConfigServerHide.flatten_links_delay;
    event_add(&event_write_links_file, NULL);
  }

  log_write(LOG_TYPE_IRCD, "Server ready. Running version: %s", IRCD_VERSION);
  io_loop();

  return 0;
}
