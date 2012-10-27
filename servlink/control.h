/************************************************************************
 *   IRC - Internet Relay Chat, servlink/control.h
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *   $Id$
 */

#ifndef INCLUDED_servlink_control_h
#define INCLUDED_servlink_control_h

#define CMD_SET_ZIP_OUT_LEVEL           1       /* data */
#define CMD_START_ZIP_OUT               2
#define CMD_START_ZIP_IN                3
#define CMD_SET_CRYPT_IN_CIPHER         4       /* data */
#define CMD_SET_CRYPT_IN_KEY            5       /* data */
#define CMD_START_CRYPT_IN              6
#define CMD_SET_CRYPT_OUT_CIPHER        7       /* data */
#define CMD_SET_CRYPT_OUT_KEY           8       /* data */
#define CMD_START_CRYPT_OUT             9 
#define CMD_INJECT_RECVQ                10      /* data */
#define CMD_INJECT_SENDQ                11      /* data */
#define CMD_INIT                        12
#define CMD_ZIPSTATS                    13

#define RPL_ERROR                       1       /* data */
#define RPL_ZIPSTATS                    2       /* data */

/* flags */
#define COMMAND_FLAG_DATA               0x0001  /* command has data
                                                   following */           
struct ctrl_command
{
  unsigned int command;
  int datalen;
  int gotdatalen;
  int readdata;
  unsigned char *data;
};

typedef void cmd_handler(struct ctrl_command *);

struct command_def
{
  unsigned int  commandid;
  cmd_handler   *handler;
  unsigned int  flags;
};

extern struct command_def command_table[];
#endif /* INCLUDED_servlink_control_h */
