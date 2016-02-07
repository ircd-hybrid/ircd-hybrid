/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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

/*! \file ircd.c
 * \brief Starts up and runs the ircd.
 * \version $Id$
 */

#include "stdinc.h"
#include "user.h"
#include "list.h"
#include "ircd.h"
#include "channel.h"
#include "client.h"
#include "event.h"
#include "fdlist.h"
#include "hash.h"
#include "id.h"
#include "irc_string.h"
#include "ircd_signal.h"
#include "motd.h"
#include "conf.h"
#include "hostmask.h"
#include "parse.h"
#include "res.h"
#include "restart.h"
#include "rng_mt.h"
#include "auth.h"
#include "s_bsd.h"
#include "log.h"
#include "server.h"
#include "send.h"
#include "whowas.h"
#include "modules.h"
#include "memory.h"
#include "mempool.h"
#include "ircd_getopt.h"
#include "watch.h"
#include "conf_db.h"
#include "conf_class.h"
#include "ipcache.h"
#include "isupport.h"
#include "userhost.h"


#ifdef HAVE_LIBGEOIP
GeoIP *GeoIPv4_ctx;
GeoIP *GeoIPv6_ctx;
#endif

struct SetOptions GlobalSetOptions;  /* /quote set variables */
struct Counter Count;
struct ServerState_t server_state;
struct ServerStatistics ServerStats;
struct timeval SystemTime;
struct Connection meConnection;  /* That's also part of me */
struct Client me = { .connection = &meConnection };  /* That's me */

char **myargv;
const char *logFileName = LPATH;
const char *pidFileName = PPATH;

unsigned int dorehash;
unsigned int doremotd;

static int printVersion;

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
   YESNO, "Run in foreground (don't detach)" },
  { "version",    &printVersion,
   YESNO, "Print version and exit" },
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
  .when = STARTUP_CONNECTIONS_TIME
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


void
set_time(void)
{
  struct timeval newtime = { .tv_sec = 0, .tv_usec = 0 };

  if (gettimeofday(&newtime, NULL) == -1)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "Clock failure, TS can be corrupted: %s",
             strerror(errno));
    server_die(buf, SERVER_SHUTDOWN);
  }

  if (newtime.tv_sec < CurrentTime)
  {
    ilog(LOG_TYPE_IRCD, "System clock is running backwards - (%ju < %ju)",
         newtime.tv_sec, CurrentTime);
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "System clock is running backwards - (%ju < %ju)",
                         newtime.tv_sec, CurrentTime);
    event_set_back_events(CurrentTime - newtime.tv_sec);
  }

  SystemTime.tv_sec = newtime.tv_sec;
  SystemTime.tv_usec = newtime.tv_usec;
}

static void
io_loop(void)
{
  while (1)
  {
    if (listing_client_list.head)
    {
      dlink_node *node = NULL, *node_next = NULL;
      DLINK_FOREACH_SAFE(node, node_next, listing_client_list.head)
        safe_list_channels(node->data, 0);
    }

    /* Run pending events */
    event_run();

    comm_select();
    exit_aborted_clients();
    free_exited_clients();

    /* Check to see whether we have to rehash the configuration. */
    if (dorehash)
    {
      conf_rehash(1);
      dorehash = 0;
    }

    if (doremotd)
    {
      motd_recache();
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "Got signal SIGUSR1, reloading motd file(s)");
      doremotd = 0;
    }
  }
}

/* initalialize_global_set_options()
 *
 * inputs       - none
 * output       - none
 * side effects - This sets all global set options needed
 */
static void
initialize_global_set_options(void)
{
  GlobalSetOptions.maxclients = ConfigServerInfo.default_max_clients;
  GlobalSetOptions.autoconn = 1;
  GlobalSetOptions.spam_time = MIN_JOIN_LEAVE_TIME;
  GlobalSetOptions.spam_num = MAX_JOIN_LEAVE_COUNT;
  GlobalSetOptions.floodcount = ConfigGeneral.default_floodcount;
  GlobalSetOptions.joinfloodcount = ConfigChannel.default_join_flood_count;
  GlobalSetOptions.joinfloodtime = ConfigChannel.default_join_flood_time;
  GlobalSetOptions.ident_timeout = IDENT_TIMEOUT;
}

/* initialize_server_capabs()
 *
 * inputs       - none
 * output       - none
 */
static void
initialize_server_capabs(void)
{
  add_capability("QS", CAPAB_QS);
  add_capability("EOB", CAPAB_EOB);
  add_capability("CLUSTER", CAPAB_CLUSTER);
  add_capability("SVS", CAPAB_SVS);
  add_capability("CHW", CAPAB_CHW);
  add_capability("HOPS", CAPAB_HOPS);
}

/* write_pidfile()
 *
 * inputs       - filename+path of pid file
 * output       - NONE
 * side effects - write the pid of the ircd to filename
 */
static void
write_pidfile(const char *filename)
{
  FILE *fb;

  if ((fb = fopen(filename, "w")))
  {
    char buf[IRCD_BUFSIZE];
    unsigned int pid = (unsigned int)getpid();

    snprintf(buf, sizeof(buf), "%u\n", pid);

    if (fputs(buf, fb) == -1)
      ilog(LOG_TYPE_IRCD, "Error writing to pid file %s: %s",
           filename, strerror(errno));

    fclose(fb);
  }
  else
    ilog(LOG_TYPE_IRCD, "Error opening pid file %s: %s",
         filename, strerror(errno));
}

/* check_pidfile()
 *
 * inputs       - filename+path of pid file
 * output       - none
 * side effects - reads pid from pidfile and checks if ircd is in process
 *                list. if it is, gracefully exits
 * -kre
 */
static void
check_pidfile(const char *filename)
{
  FILE *fb;
  char buf[IRCD_BUFSIZE];

  if ((fb = fopen(filename, "r")))
  {
    if (!fgets(buf, 20, fb))
      ilog(LOG_TYPE_IRCD, "Error reading from pid file %s: %s",
           filename, strerror(errno));
    else
    {
      pid_t pid = atoi(buf);

      if (!kill(pid, 0))
      {
        /* log(L_ERROR, "Server is already running"); */
        printf("ircd: daemon is already running\n");
        exit(EXIT_FAILURE);
      }
    }

    fclose(fb);
  }
  else if (errno != ENOENT)
    ilog(LOG_TYPE_IRCD, "Error opening pid file %s: %s",
         filename, strerror(errno));
}

/* setup_corefile()
 *
 * inputs       - nothing
 * output       - nothing
 * side effects - setups corefile to system limits.
 * -kre
 */
static void
setup_corefile(void)
{
#ifdef HAVE_SYS_RESOURCE_H
  struct rlimit rlim; /* resource limits */

  /* Set corefilesize to maximum */
  if (!getrlimit(RLIMIT_CORE, &rlim))
  {
    rlim.rlim_cur = rlim.rlim_max;
    setrlimit(RLIMIT_CORE, &rlim);
  }
#endif
}

/*
 * print_startup - print startup information
 */
static void
print_startup(int pid)
{
  printf("ircd: version %s(%s)\n", ircd_version, serno);
  printf("ircd: pid %d\n", pid);
  printf("ircd: running in %s mode from %s\n", !server_state.foreground ? "background"
         : "foreground", ConfigGeneral.dpath);
}

static void
make_daemon(void)
{
  int pid;

  if ((pid = fork()) < 0)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid > 0)
  {
    print_startup(pid);
    exit(EXIT_SUCCESS);
  }

  setsid();
}

int
main(int argc, char *argv[])
{
  /* Check to see if the user is running us as root, which is a nono */
  if (!geteuid())
  {
    fprintf(stderr, "ERROR: This server won't run as root/superuser\n");
    return -1;
  }

  /* Setup corefile size immediately after boot -kre */
  setup_corefile();

  /* Save server boot time right away, so getrusage works correctly */
  set_time();

  /* It's not random, but it ought to be a little harder to guess */
  init_genrand(SystemTime.tv_sec ^ (SystemTime.tv_usec | (getpid() << 20)));

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

  parseargs(&argc, &argv, myopts);

  if (printVersion)
  {
    printf("ircd: version %s(%s)\n", ircd_version, serno);
    exit(EXIT_SUCCESS);
  }

  if (chdir(ConfigGeneral.dpath))
  {
    perror("chdir");
    exit(EXIT_FAILURE);
  }

  if (!server_state.foreground)
  {
    make_daemon();
    close_standard_fds(); /* this needs to be before init_netio()! */
  }
  else
    print_startup(getpid());

  setup_signals();

  /* We need this to initialise the fd array before anything else */
  fdlist_init();
  log_set_file(LOG_TYPE_IRCD, 0, logFileName);

  init_netio();         /* This needs to be setup early ! -- adrian */
  tls_init();

  /* Check if there is pidfile and daemon already running */
  check_pidfile(pidFileName);

  mp_pool_init();
  init_dlink_nodes();
  isupport_init();
  dbuf_init();
  hash_init();
  userhost_init();
  ipcache_init();
  client_init();
  class_init();
  whowas_init();
  watch_init();
  auth_init();          /* Initialise the auth code */
  init_resolver();      /* Needs to be setup before the io loop */
  modules_init();
  read_conf_files(1);   /* cold start init conf files */
  initialize_server_capabs();   /* Set up default_server_capabs */
  initialize_global_set_options();  /* Has to be called after read_conf_files() */
  channel_init();
  read_links_file();
  motd_init();
  user_modes_init();

  if (EmptyString(ConfigServerInfo.name))
  {
    ilog(LOG_TYPE_IRCD, "ERROR: No server name specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.name, ConfigServerInfo.name, sizeof(me.name));

  /* serverinfo {} description must exist.  If not, error out.*/
  if (EmptyString(ConfigServerInfo.description))
  {
    ilog(LOG_TYPE_IRCD, "ERROR: No server description specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));

  if (EmptyString(ConfigServerInfo.sid))
  {
    ilog(LOG_TYPE_IRCD, "Generating server ID");
    generate_sid();
  }
  else
    strlcpy(me.id, ConfigServerInfo.sid, sizeof(me.id));

  init_uid();

  me.from = &me;
  me.servptr = &me;
  me.connection->lasttime = CurrentTime;
  me.connection->since = CurrentTime;
  me.connection->firsttime = CurrentTime;

  SetMe(&me);
  make_server(&me);

  hash_add_id(&me);
  hash_add_client(&me);

  dlinkAdd(&me, make_dlink_node(), &global_server_list);
  dlinkAdd(&me, &me.node, &global_client_list);

  load_kline_database(ConfigGeneral.klinefile);
  load_dline_database(ConfigGeneral.dlinefile);
  load_xline_database(ConfigGeneral.xlinefile);
  load_resv_database(ConfigGeneral.resvfile);

  load_all_modules(1);
  load_conf_modules();
  load_core_modules(1);

  write_pidfile(pidFileName);

  event_addish(&event_cleanup_tklines, NULL);

  /* We want try_connections to be called as soon as possible now! -- adrian */
  /* No, 'cause after a restart it would cause all sorts of nick collides */
  event_addish(&event_try_connections, NULL);

  /* Setup the timeout check. I'll shift it later :)  -- adrian */
  event_add(&event_comm_checktimeouts, NULL);

  event_addish(&event_save_all_databases, NULL);

  if (ConfigServerHide.flatten_links_delay && event_write_links_file.active == 0)
  {
    event_write_links_file.when = ConfigServerHide.flatten_links_delay;
    event_add(&event_write_links_file, NULL);
  }

  ilog(LOG_TYPE_IRCD, "Server Ready");
  io_loop();

  return 0;
}
