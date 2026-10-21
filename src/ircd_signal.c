/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file ircd_signal.c
 * @brief Implements signal handling for the IRC daemon.
 *
 * Control signals are deferred to the main loop. SIGCHLD reaps child processes
 * directly using async-signal-safe operations.
 */

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#include "io.h"
#include "io_signal.h"
#include "log.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "ircd_exit.h"
#include "ircd_signal.h"
#include "motd.h"
#include "send.h"

static sigset_t deferred_signals;

static volatile sig_atomic_t pending_sigterm;
static volatile sig_atomic_t pending_sigint;
static volatile sig_atomic_t pending_sighup;
static volatile sig_atomic_t pending_sigusr1;


/**
 * @brief Records control requests and reaps child processes.
 *
 * @param signum Signal number.
 */
static void
_ircd_signal_handler(int signum)
{
  switch (signum)
  {
    case SIGTERM:
      pending_sigterm = 1;
      break;
    case SIGINT:
      pending_sigint = 1;
      break;
    case SIGHUP:
      pending_sighup = 1;
      break;
    case SIGUSR1:
      pending_sigusr1 = 1;
      break;
    case SIGCHLD:
    {
      const int saved_errno = errno;
      pid_t result;

      /* Reap all available children, including after nested signals. */
      do
        result = waitpid(-1, NULL, WNOHANG);
      while (result > 0 || (result == -1 && errno == EINTR));

      errno = saved_errno;
      break;
    }
    default:
      break;
  }
}


void
ircd_signal_process(void)
{
  if (!pending_sigterm && !pending_sigint && !pending_sighup && !pending_sigusr1)
    return;

  sigset_t previous_mask;
  if (sigprocmask(SIG_BLOCK, &deferred_signals, &previous_mask) == -1)
    ircd_exit_fmt(IRCD_EXIT_FAILURE, "Unable to block control signals: %s", strerror(errno));

  const sig_atomic_t terminate = pending_sigterm;
  const sig_atomic_t interrupt = pending_sigint;
  const sig_atomic_t rehash = pending_sighup;
  const sig_atomic_t reload_motd = pending_sigusr1;

  pending_sigterm = 0;
  pending_sigint = 0;
  pending_sighup = 0;
  pending_sigusr1 = 0;

  if (sigprocmask(SIG_SETMASK, &previous_mask, NULL) == -1)
    ircd_exit_fmt(IRCD_EXIT_FAILURE, "Unable to restore signal mask: %s", strerror(errno));

  if (terminate)
    ircd_exit(IRCD_EXIT_TERMINATE, "received signal SIGTERM");

  if (interrupt)
    ircd_exit(server_state.foreground ? IRCD_EXIT_TERMINATE : IRCD_EXIT_RESTART, "received signal SIGINT");

  if (rehash)
  {
    conf_rehash();

    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Got signal SIGHUP, reloading configuration file(s)");
    log_write(LOG_TYPE_IRCD, "Got signal SIGHUP, reloading configuration file(s)");
  }

  if (reload_motd)
  {
    motd_recache();

    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Got signal SIGUSR1, reloading motd file(s)");
    log_write(LOG_TYPE_IRCD, "Got signal SIGUSR1, reloading motd file(s)");
  }
}


/**
 * @brief Initializes signal handlers for the IRC daemon.
 *
 * This function sets up signal handlers for various signals using the
 * io_signal_register API. It also ignores certain signals that do not need
 * to be handled.
 */
void
ircd_signal_init(void)
{
  const io_signal_t signals[] =
  {
    { SIGTERM, _ircd_signal_handler },
    { SIGINT, _ircd_signal_handler },
    { SIGHUP, _ircd_signal_handler },
    { SIGUSR1, _ircd_signal_handler },
    { SIGCHLD, _ircd_signal_handler }
  };

  const int ignore_signals[] =
  {
    SIGPIPE,
    SIGALRM,
#ifdef SIGXFSZ
    SIGXFSZ,
#endif
#ifdef SIGWINCH
    SIGWINCH,
#endif
#ifdef SIGTRAP
    SIGTRAP,
#endif
  };

  sigemptyset(&deferred_signals);
  sigaddset(&deferred_signals, SIGTERM);
  sigaddset(&deferred_signals, SIGINT);
  sigaddset(&deferred_signals, SIGHUP);
  sigaddset(&deferred_signals, SIGUSR1);

  if (io_signal_register(signals, IO_ARRAY_LENGTH(signals)) == -1)
  {
    fprintf(stderr, "Failed to set up signal handlers\n");
    exit(EXIT_FAILURE);
  }

  if (io_signal_ignore(ignore_signals, IO_ARRAY_LENGTH(ignore_signals)) == -1)
  {
    fprintf(stderr, "Failed to ignore signals\n");
    exit(EXIT_FAILURE);
  }
}
