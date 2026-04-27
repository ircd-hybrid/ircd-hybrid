/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

#include <jansson.h>  /**< Jansson JSON library. */

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "comm.h"
#include "event.h"
#include "fdlist.h"
#include "io_daemon.h"
#include "io_getopt.h"
#include "io_pidfile.h"
#include "io_rlimit.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "module.h"
#include "res.h"
#include "rng_mt.h"

#include "channel_mode.h"
#include "client.h"
#include "client_id.h"
#include "cloak.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_db.h"
#include "defaults.h"
#include "extban.h"
#include "hash.h"
#include "ipcache.h"
#include "ircd.h"
#include "ircd_exit.h"
#include "ircd_hook.h"
#include "ircd_signal.h"
#include "links_cache.h"
#include "motd.h"
#include "send.h"
#include "server.h"
#include "server_capab.h"

event_manager_t ircd_event_manager;

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

/**
 * @brief Main IO loop for processing events and managing server activities.
 *
 * This function runs continuously, handling various tasks such as
 * processing events, checking for rehash signals, and managing client connections.
 */
static void
_io_loop(void)
{
  while (true)
  {
    comm_select(comm_get_select_timeout(ircd_event_manager));
    exit_aborted_clients();
    free_exited_clients();

    io_time_update_cache();
    event_run(ircd_event_manager);

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
_initialize_global_set_options(void)
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
_ircd_oom(void)
{
  ircd_exit(IRCD_EXIT_RESTART, "out of memory");
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
_ircd_time_failure(enum io_time_error_code error_code, const char *message)
{
  if (error_code == IO_TIME_ERR_INIT)
  {
    fprintf(stderr, "ERROR: %s\n", message);
    exit(EXIT_FAILURE);  /* Exit with failure if initialization error. */
  }

  ircd_exit(IRCD_EXIT_RESTART, message);  /* Restart the program for other errors. */
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
_ircd_print_startup(pid_t pid)
{
  printf("ircd: version %s\n", IRCD_VERSION);
  printf("ircd: pid %d\n", pid);
  printf("ircd: running in %s mode from %s\n",
         server_state.foreground ? "foreground": "background", ConfigGeneral.dpath);
}

static void
_ircd_init_me(void)
{
  if (string_is_empty(ConfigServerInfo.name))
  {
    log_write(LOG_TYPE_IRCD, "ERROR: No server name specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.name, ConfigServerInfo.name, sizeof(me.name));

  if (string_is_empty(ConfigServerInfo.description))
  {
    log_write(LOG_TYPE_IRCD, "ERROR: No server description specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));

  if (string_is_empty(ConfigServerInfo.sid))
    log_write(LOG_TYPE_IRCD, "Generating server ID");

  bool sid_generated = false;
  if (!client_id_set_server_sid(&me, ConfigServerInfo.sid, ConfigServerInfo.name,
                                ConfigServerInfo.description, &sid_generated))
  {
    log_write(LOG_TYPE_IRCD, "ERROR: Failed to initialize server ID.");
    exit(EXIT_FAILURE);
  }

  if (sid_generated)
    ConfigServerInfo.sid = io_strdup(me.id);

  if (!client_id_init_generator(&me))
  {
    log_write(LOG_TYPE_IRCD, "ERROR: Failed to initialize client ID generator.");
    exit(EXIT_FAILURE);
  }

  me.uplink = &me;
  me.nexthop = &me;
  me.connection->created_real = io_time_get(IO_TIME_REALTIME_SEC);
  me.connection->created_monotonic = io_time_get(IO_TIME_MONOTONIC_SEC);

  client_set_state(&me, CLIENT_STATE_ME);
  server_get_or_create(&me);

  hash_add_id(&me);
  hash_add_client(&me);

  list_add(&me, &me.global_node, &global_server_list);
}

static void
_ircd_daemonize(void)
{
  pid_t child_pid;
  const io_daemon_result_t result = io_daemonize(&child_pid);

  switch (result)
  {
    case IO_DAEMON_PARENT:
      _ircd_print_startup(child_pid);
      exit(EXIT_SUCCESS);
    case IO_DAEMON_CHILD:
      return;
    case IO_DAEMON_ERROR:
      perror("daemonize");
      exit(EXIT_FAILURE);
  }

  assert(!"unreachable");
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

  io_set_oom_handler(_ircd_oom);

  io_rlimit_set_max_core();

  io_rlimit_set_max_nofile();

  io_time_set_error_callback(_ircd_time_failure);
  io_time_init();

  /* Configure libjansson to use io_calloc and io_free. */
  json_set_alloc_funcs(io_calloc, io_free);

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
    _ircd_print_startup(getpid());
  else
    _ircd_daemonize();

  ircd_signal_init();

  ircd_event_manager = event_manager_create(NULL);
  if (ircd_event_manager == NULL)
  {
    exit(EXIT_FAILURE);
  }

  /* We need this to initialise the fd array before anything else */
  fdlist_init();
  log_add(LOG_TYPE_IRCD, true, 0, logFileName);

  comm_init(ircd_event_manager);  /* This needs to be setup early ! -- adrian */
  tls_init();

  /* Check if there is pidfile and daemon already running */
  if (io_pidfile_create(pidFileName))
    exit(EXIT_FAILURE);

  ircd_hook_init();
  class_init();
  cloak_init();
  module_init();
  conf_read_files(true);   /* cold start init conf files */

  resolver_init(ircd_event_manager);
  ipcache_init();
  channel_mode_init();
  extban_init();
  capab_init();  /* Set up default_server_capabs */
  _initialize_global_set_options();  /* Has to be called after conf_read_files() */
  links_cache_init();
  _ircd_init_me();

  load_kline_database(ConfigGeneral.klinefile);
  load_dline_database(ConfigGeneral.dlinefile);
  load_xline_database(ConfigGeneral.xlinefile);
  load_resv_database(ConfigGeneral.resvfile);

  module_load_all(NULL);

  event_handle_t event_cleanup_tklines =
    event_create(ircd_event_manager, "cleanup_tklines", cleanup_tklines, 30000, false, NULL, NULL);
  event_schedule_fuzzed(event_cleanup_tklines);

  event_handle_t event_server_connect_auto =
    event_create(ircd_event_manager, "server_connect_auto", server_connect_auto, 15000, false, NULL, NULL);
  event_schedule_fuzzed(event_server_connect_auto);

  event_handle_t event_save_all_databases =
    event_create(ircd_event_manager, "save_all_databases", save_all_databases, 300000, false, NULL, NULL);
  event_schedule_fuzzed(event_save_all_databases);

  log_write(LOG_TYPE_IRCD, "Server ready. Running version: %s", IRCD_VERSION);
  _io_loop();

  return 0;
}
