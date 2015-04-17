/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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
#include "irc_string.h"
#include "ircd_signal.h"
#include "gline.h"
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
#include "server.h"      /* try_connections */
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


#ifdef HAVE_LIBGEOIP
GeoIP *geoip_ctx;
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
unsigned int splitmode;
unsigned int splitchecking;
unsigned int split_users;
unsigned int split_servers;

static struct event event_cleanup_glines =
{
  .name = "cleanup_glines",
  .handler = cleanup_glines,
  .when = CLEANUP_GLINES_TIME
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

static int printVersion = 0;

static struct lgetopt myopts[] =
{
  {"configfile", &ConfigGeneral.configfile,
   STRING, "File to use for ircd.conf"},
  {"glinefile",  &ConfigGeneral.glinefile,
   STRING, "File to use for gline database"},
  {"klinefile",  &ConfigGeneral.klinefile,
   STRING, "File to use for kline database"},
  {"dlinefile",  &ConfigGeneral.dlinefile,
   STRING, "File to use for dline database"},
  {"xlinefile",  &ConfigGeneral.xlinefile,
   STRING, "File to use for xline database"},
  {"resvfile",  &ConfigGeneral.resvfile,
   STRING, "File to use for resv database"},
  {"logfile",    &logFileName,
   STRING, "File to use for ircd.log"},
  {"pidfile",    &pidFileName,
   STRING, "File to use for process ID"},
  {"foreground", &server_state.foreground,
   YESNO, "Run in foreground (don't detach)"},
  {"version",    &printVersion,
   YESNO, "Print version and exit"},
  {"help", NULL, USAGE, "Print this text"},
  {NULL, NULL, STRING, NULL},
};

void
set_time(void)
{
  struct timeval newtime = { .tv_sec = 0, .tv_usec = 0 };

  if (gettimeofday(&newtime, NULL) == -1)
  {
    ilog(LOG_TYPE_IRCD, "Clock Failure (%s), TS can be corrupted",
         strerror(errno));
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Clock Failure (%s), TS can be corrupted",
                         strerror(errno));
    server_die("Clock Failure", 1);
  }

  if (newtime.tv_sec < CurrentTime)
  {
    ilog(LOG_TYPE_IRCD, "System clock is running backwards - (%lu < %lu)",
         (unsigned long)newtime.tv_sec, (unsigned long)CurrentTime);
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "System clock is running backwards - (%lu < %lu)",
                         (unsigned long)newtime.tv_sec,
                         (unsigned long)CurrentTime);
    set_back_events(CurrentTime - newtime.tv_sec);
  }

  SystemTime.tv_sec  = newtime.tv_sec;
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

    /* Check to see whether we have to rehash the configuration .. */
    if (dorehash)
    {
      conf_rehash(1);
      dorehash = 0;
    }

    if (doremotd)
    {
      motd_recache();
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
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

  split_servers = ConfigChannel.default_split_server_count;
  split_users   = ConfigChannel.default_split_user_count;

  if (split_users && split_servers && (ConfigChannel.no_create_on_split ||
                                       ConfigChannel.no_join_on_split))
  {
    splitmode     = 1;
    splitchecking = 1;
  }

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
  add_capability("QS", CAP_QS);
  add_capability("EOB", CAP_EOB);
  add_capability("CLUSTER", CAP_CLUSTER);
  add_capability("SVS", CAP_SVS);
  add_capability("CHW", CAP_CHW);
  add_capability("HOPS", CAP_HOPS);
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
    char buff[IRCD_BUFSIZE];
    unsigned int pid = (unsigned int)getpid();

    snprintf(buff, sizeof(buff), "%u\n", pid);

    if (fputs(buff, fb) == -1)
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
  char buff[IRCD_BUFSIZE];
  pid_t pidfromfile;

  /* Don't do logging here, since we don't have log() initialised */
  if ((fb = fopen(filename, "r")))
  {
    if (!fgets(buff, 20, fb))
    {
      /* log(L_ERROR, "Error reading from pid file %s (%s)", filename,
       * strerror(errno));
       */
    }
    else
    {
      pidfromfile = atoi(buff);

      if (!kill(pidfromfile, 0))
      {
        /* log(L_ERROR, "Server is already running"); */
        printf("ircd: daemon is already running\n");
        exit(-1);
      }
    }

    fclose(fb);
  }
  else if (errno != ENOENT)
  {
    /* log(L_ERROR, "Error opening pid file %s", filename); */
  }
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

#ifdef HAVE_LIBCRYPTO
static int
always_accept_verify_cb(int preverify_ok, X509_STORE_CTX *x509_ctx)
{
  return 1;
}
#endif

/* init_ssl()
 *
 * inputs       - nothing
 * output       - nothing
 * side effects - setups SSL context.
 */
static void
ssl_init(void)
{
#ifdef HAVE_LIBCRYPTO
  SSL_load_error_strings();
  SSLeay_add_ssl_algorithms();

  if (!(ConfigServerInfo.server_ctx = SSL_CTX_new(SSLv23_server_method())))
  {
    const char *s = ERR_lib_error_string(ERR_get_error());

    fprintf(stderr, "ERROR: Could not initialize the SSL Server context -- %s\n", s);
    ilog(LOG_TYPE_IRCD, "ERROR: Could not initialize the SSL Server context -- %s", s);
    exit(EXIT_FAILURE);
    return;  /* Not reached */
  }

  SSL_CTX_set_options(ConfigServerInfo.server_ctx, SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3|SSL_OP_NO_TICKET);
  SSL_CTX_set_options(ConfigServerInfo.server_ctx, SSL_OP_SINGLE_DH_USE|SSL_OP_CIPHER_SERVER_PREFERENCE);
  SSL_CTX_set_verify(ConfigServerInfo.server_ctx, SSL_VERIFY_PEER|SSL_VERIFY_CLIENT_ONCE,
                     always_accept_verify_cb);
  SSL_CTX_set_session_cache_mode(ConfigServerInfo.server_ctx, SSL_SESS_CACHE_OFF);
  SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, "EECDH+HIGH:EDH+HIGH:HIGH:!aNULL");

#if OPENSSL_VERSION_NUMBER >= 0x009080FFL && !defined(OPENSSL_NO_ECDH)
  {
    EC_KEY *key = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);

    if (key)
    {
      SSL_CTX_set_tmp_ecdh(ConfigServerInfo.server_ctx, key);
      EC_KEY_free(key);
    }
  }

  SSL_CTX_set_options(ConfigServerInfo.server_ctx, SSL_OP_SINGLE_ECDH_USE);
#endif

  if (!(ConfigServerInfo.client_ctx = SSL_CTX_new(SSLv23_client_method())))
  {
    const char *s = ERR_lib_error_string(ERR_get_error());

    fprintf(stderr, "ERROR: Could not initialize the SSL Client context -- %s\n", s);
    ilog(LOG_TYPE_IRCD, "ERROR: Could not initialize the SSL Client context -- %s", s);
    exit(EXIT_FAILURE);
    return;  /* Not reached */
  }

  SSL_CTX_set_options(ConfigServerInfo.client_ctx, SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3|SSL_OP_NO_TICKET);
  SSL_CTX_set_options(ConfigServerInfo.client_ctx, SSL_OP_SINGLE_DH_USE);
  SSL_CTX_set_verify(ConfigServerInfo.client_ctx, SSL_VERIFY_PEER|SSL_VERIFY_CLIENT_ONCE,
                     always_accept_verify_cb);
  SSL_CTX_set_session_cache_mode(ConfigServerInfo.client_ctx, SSL_SESS_CACHE_OFF);
#endif /* HAVE_LIBCRYPTO */
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

  dlinkAdd(&me, &me.node, &global_client_list);

  ConfigGeneral.dpath      = DPATH;
  ConfigGeneral.spath      = SPATH;
  ConfigGeneral.mpath      = MPATH;
  ConfigGeneral.configfile = CPATH;    /* Server configuration file */
  ConfigGeneral.klinefile  = KPATH;    /* Server kline file         */
  ConfigGeneral.glinefile  = GPATH;    /* Server gline file         */
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

  ssl_init();

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

  /* Check if there is pidfile and daemon already running */
  check_pidfile(pidFileName);

  mp_pool_init();
  init_dlink_nodes();
  init_isupport();
  dbuf_init();
  hash_init();
  ipcache_init();
  client_init();
  class_init();
  whowas_init();
  watch_init();
  auth_init();          /* Initialise the auth code */
  init_resolver();      /* Needs to be setup before the io loop */
  modules_init();
  read_conf_files(1);   /* cold start init conf files */
  init_uid();
  initialize_server_capabs();   /* Set up default_server_capabs */
  initialize_global_set_options();  /* Has to be called after read_conf_files() */
  channel_init();
  read_links_file();
  motd_init();
  user_usermodes_init();
#ifdef HAVE_LIBGEOIP
  geoip_ctx = GeoIP_new(GEOIP_MEMORY_CACHE);
#endif

  if (EmptyString(ConfigServerInfo.sid))
  {
    ilog(LOG_TYPE_IRCD, "ERROR: No server id specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.id, ConfigServerInfo.sid, sizeof(me.id));

  if (EmptyString(ConfigServerInfo.name))
  {
    ilog(LOG_TYPE_IRCD, "ERROR: No server name specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.name, ConfigServerInfo.name, sizeof(me.name));

  /* serverinfo{} description must exist.  If not, error out.*/
  if (EmptyString(ConfigServerInfo.description))
  {
    ilog(LOG_TYPE_IRCD, "ERROR: No server description specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));

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

  load_kline_database();
  load_dline_database();
  load_gline_database();
  load_xline_database();
  load_resv_database();

  load_all_modules(1);
  load_conf_modules();
  load_core_modules(1);

  write_pidfile(pidFileName);

  ilog(LOG_TYPE_IRCD, "Server Ready");

  event_addish(&event_cleanup_glines, NULL);
  event_addish(&event_cleanup_tklines, NULL);

  /* We want try_connections to be called as soon as possible now! -- adrian */
  /* No, 'cause after a restart it would cause all sorts of nick collides */
  event_addish(&event_try_connections, NULL);

  /* Setup the timeout check. I'll shift it later :)  -- adrian */
  event_add(&event_comm_checktimeouts, NULL);

  event_addish(&event_save_all_databases, NULL);

  if (ConfigServerHide.links_delay > 0)
  {
    event_write_links_file.when = ConfigServerHide.links_delay;
    event_addish(&event_write_links_file, NULL);
  }
  else
    ConfigServerHide.links_disabled = 1;

  if (splitmode)
    event_addish(&splitmode_event, NULL);

  io_loop();
  return 0;
}
