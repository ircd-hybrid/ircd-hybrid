/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd_lexer.l: Scans the ircd configuration file for tokens.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

%option case-insensitive
%option noyywrap
%option nounput
%option never-interactive

%{
#include "stdinc.h"
#include "tools.h"
#include "irc_string.h"
#include "common.h"
#include "s_conf.h"
#include "memory.h"
#include "hostmask.h"
#include "s_log.h"

#include "y.tab.h"

#undef YY_INPUT
#define YY_FATAL_ERROR(msg) conf_yy_fatal_error(msg)
#define YY_INPUT(buf,result,max_size) \
  if (!(result = conf_fbgets(buf, max_size, conf_fbfile_in))) \
    YY_FATAL_ERROR("input in flex scanner failed"); 
#define MAX_INCLUDE_DEPTH 10


unsigned int lineno = 1;
char linebuf[IRCD_BUFSIZE];
char conffilebuf[IRCD_BUFSIZE];

static int include_stack_ptr = 0;
static YY_BUFFER_STATE include_stack[MAX_INCLUDE_DEPTH];
static unsigned int lineno_stack[MAX_INCLUDE_DEPTH];
static FBFILE *inc_fbfile_in[MAX_INCLUDE_DEPTH];
static char conffile_stack[MAX_INCLUDE_DEPTH][IRCD_BUFSIZE];
static void ccomment(void);
static void cinclude(void);
static int ieof(void);
%}

WS        [[:blank:]]*
DIGIT     [[:digit:]]+
COMMENT   ("//"|"#").*
qstring   \"[^\"\n]*[\"\n]
include   \.include{WS}(\<.*\>|\".*\")

%%
{include}       { cinclude(); }
"/*"	        { ccomment(); }

\n.*	        { strcpy(linebuf, yytext+1); ++lineno; yyless(1); }

{WS}            ;
{COMMENT}       ;

{DIGIT}         { yylval.number = atoi(yytext); return NUMBER; }

{qstring}	{ if (yytext[yyleng-2] == '\\')
		    {
		      yyless(yyleng-1); /* return last quote */
		      yymore();		/* append next string */
		    }
		  else
		    {
		      yylval.string = yytext+1;
		      if(yylval.string[yyleng-2] != '"')
			ilog(L_ERROR, "Unterminated character string");
		      else
			{
			  int i,j;

			  yylval.string[yyleng-2] = '\0'; /* remove close
							   *  quote 
							   */
			  
			  for (j=i=0 ;yylval.string[i] != '\0'; i++,j++)
			    {
			      if (yylval.string[i] != '\\')
				{
				  yylval.string[j] = yylval.string[i];
				}
			      else
				{
				  i++;
				  if (yylval.string[i] == '\0') /* XXX 
								 * should not
								 * happen
								 */
				    {
				      ilog(L_ERROR,
					   "Unterminated character string");
				      break;
				    }
				  yylval.string[j] = yylval.string[i];
				}
			    }
			  yylval.string[j] = '\0';
			  return QSTRING;
			}
		    }
		}

~		{ return NOT; }
accept_password { return ACCEPT_PASSWORD; }
action		{ return ACTION; }
admin		{ return ADMIN; }
administrator	{ return ADMIN; }
aftype		{ return AFTYPE; }
all		{ return T_ALL; }
allow		{ return T_ALLOW; }
auth		{ return IRCD_AUTH; }
autoconn	{ return AUTOCONN; }
block		{ return T_BLOCK; }
burst_away      { return BURST_AWAY; }
burst_topicwho  { return BURST_TOPICWHO; }
can_flood	{ return CAN_FLOOD; }
can_idle        { return CAN_IDLE; }
caller_id_wait	{ return CALLER_ID_WAIT; }
opers_bypass_callerid  { return OPERS_BYPASS_CALLERID; }
channel		{ return CHANNEL; }
cidr_bitlen_ipv4	{ return CIDR_BITLEN_IPV4; }
cidr_bitlen_ipv6	{ return CIDR_BITLEN_IPV6; }
cipher_preference { return CIPHER_PREFERENCE; }
class		{ return CLASS; }
client_flood	{ return T_CLIENT_FLOOD; }
cluster		{ return T_CLUSTER; }
compressed	{ return COMPRESSED; }
compression_level { return COMPRESSION_LEVEL; }
connect		{ return CONNECT; }
connectfreq     { return CONNECTFREQ; }
cryptlink	{ return CRYPTLINK; }
default_cipher_preference { return DEFAULT_CIPHER_PREFERENCE; }
default_floodcount  { return DEFAULT_FLOODCOUNT; }
default_split_server_count { return DEFAULT_SPLIT_SERVER_COUNT; }
default_split_user_count   { return DEFAULT_SPLIT_USER_COUNT; }
deny		{ return DENY; }
description	{ return DESCRIPTION; }
die		{ return DIE; }
disable_auth    { return DISABLE_AUTH; }
disable_fake_channels { return DISABLE_FAKE_CHANNELS; }
disable_hidden	{ return DISABLE_HIDDEN; }
disable_local_channels { return DISABLE_LOCAL_CHANNELS; }
disable_remote_commands	{ return DISABLE_REMOTE_COMMANDS; }
dot_in_ip6_addr { return DOT_IN_IP6_ADDR; }
dots_in_ident   { return DOTS_IN_IDENT; }
duration	{ return DURATION; }
egdpool_path        { return EGDPOOL_PATH; }
email		{ return EMAIL; }
enable		{ return ENABLE; }
encrypted       { return ENCRYPTED; }
exceed_limit    { return EXCEED_LIMIT; }
exempt		{ return EXEMPT; }
fakename	{ return FAKENAME; }
flags           { return IRCD_FLAGS; }
flatten_links	{ return FLATTEN_LINKS; }
fglinelog 	{ return FGLINELOG; }
fname_glinelog  { return FGLINELOG; }
fkilllog	{ return FKILLLOG; }
fioerrlog	{ return FIOERRLOG; }
fname_ioerrlog	{ return FIOERRLOG; }
fname_killlog	{ return FKILLLOG; }
fklinelog	{ return FKLINELOG; }
fname_klinelog	{ return FKLINELOG; }
ffailed_operlog	{ return FFAILED_OPERLOG; }
fname_operlog	{ return FOPERLOG; }
foperlog   	{ return FOPERLOG; }
fname_userlog	{ return FUSERLOG; }
fuserlog   	{ return FUSERLOG; }
gecos		{ return GECOS; }
general		{ return GENERAL; }
gline		{ return GLINE; }
glines		{ return GLINES; }
gline_exempt    { return GLINE_EXEMPT; }
gline_min_cidr  { return GLINE_MIN_CIDR; }
gline_min_cidr6 { return GLINE_MIN_CIDR6; }
global_kill	{ return GLOBAL_KILL; }
have_ident	{ return NEED_IDENT; }
need_ident	{ return NEED_IDENT; }
havent_read_conf { return HAVENT_READ_CONF; }
hidden		{ return HIDDEN; }
hidden_admin	{ return HIDDEN_ADMIN; }
hidden_name	{ return HIDDEN_NAME; }
hidden_oper	{ return HIDDEN_OPER; }
hide_server_ips	{ return HIDE_SERVER_IPS; }
hide_servers	{ return HIDE_SERVERS; }
hide_spoof_ips	{ return HIDE_SPOOF_IPS; }
host		{ return HOST; }
hub		{ return HUB; }
hub_mask	{ return HUB_MASK; }
idletime        { return IDLETIME; }
ignore_bogus_ts { return IGNORE_BOGUS_TS; }
invisible_on_connect { return INVISIBLE_ON_CONNECT; }
ip		{ return IP; }
ipv4            { return T_IPV4; }
ipv6            { return T_IPV6; }
join_flood_count { return JOIN_FLOOD_COUNT; }
join_flood_time  { return JOIN_FLOOD_TIME; }
kill		{ return KILL; }
kill_chase_time_limit { return KILL_CHASE_TIME_LIMIT; }
kline		{ return KLINE; }
kline_exempt	{ return KLINE_EXEMPT; }
l_crit		{ return T_L_CRIT; }
l_debug		{ return T_L_DEBUG; }
l_error		{ return T_L_ERROR; }
l_info		{ return T_L_INFO; }
l_notice 	{ return T_L_NOTICE; }
l_trace		{ return T_L_TRACE; }
l_warn		{ return T_L_WARN; }
lazylink	{ return LAZYLINK; }
leaf_mask	{ return LEAF_MASK; }
listen		{ return LISTEN; }
log_level	{ return LOG_LEVEL; }
log		{ return LOGGING; }
logging         { return LOGGING; }
logpath         { return T_LOGPATH; }
masked		{ return TMASKED; }
max_clients     { return T_MAX_CLIENTS; }
max_ident	{ return MAX_IDENT; }
max_local	{ return MAX_LOCAL; }
max_global	{ return MAX_GLOBAL; }
max_number	{ return MAX_NUMBER; }
message_locale	{ return MESSAGE_LOCALE; }
min_nonwildcard { return MIN_NONWILDCARD; }
min_nonwildcard_simple	{ return MIN_NONWILDCARD_SIMPLE; }
name		{ return NAME; }
need_password   { return NEED_PASSWORD; }
network_desc    { return NETWORK_DESC; }
network_name    { return NETWORK_NAME; }
nick		{ return NICK; }
nick_changes	{ return NICK_CHANGES; }
no		{ yylval.number = NO; return TBOOL; }
no_create_on_split { return NO_CREATE_ON_SPLIT; }
no_join_on_split   { return NO_JOIN_ON_SPLIT; }
no_oper_flood   { return NO_OPER_FLOOD; }
no_tilde	{ return NO_TILDE; }
number_per_cidr	{ return NUMBER_PER_CIDR; }
number_per_ip	{ return NUMBER_PER_IP; }
oper		{ return OPERATOR; }
oper_log        { return OPER_LOG; }
oper_pass_resv	{ return OPER_PASS_RESV; }
operator	{ return OPERATOR; }
passwd		{ return PASSWORD; }
password	{ return PASSWORD; }
ping_cookie	{ return PING_COOKIE; }
ping_time	{ return PING_TIME; }
ping_warning	{ return PING_WARNING; }
port		{ return PORT; }
quarantine	{ return RESV; }
quiet_on_ban    { return QUIET_ON_BAN; }
reason		{ return REASON; }
redirport       { return REDIRPORT; }
redirserv       { return REDIRSERV; }
regex           { return REGEX_T; }
rehash		{ return REHASH; }
reject		{ return T_REJECT; }
reject_hold_time { return TREJECT_HOLD_TIME; }
remote		{ return REMOTE; }
remoteban	{ return REMOTEBAN; }
restrict_channels { return RESTRICT_CHANNELS; }
resv		{ return RESV; }
resv_exempt     { return RESV_EXEMPT; }
rsa_private_key_file		{ return RSA_PRIVATE_KEY_FILE; }
rsa_public_key_file		{ return RSA_PUBLIC_KEY_FILE; }
ssl 				{ return T_SSL; }
ssl_certificate_file        { return SSL_CERTIFICATE_FILE; }
send_password	{ return SEND_PASSWORD; }
sendq		{ return SENDQ; }
serverhide	{ return SERVERHIDE; }
serverinfo	{ return SERVERINFO; }
servlink_path   { return SERVLINK_PATH; }
shared          { return T_SHARED; }
short_motd      { return SHORT_MOTD; }
sid		{ return IRCD_SID; }
silent          { return SILENT; }
spoof		{ return SPOOF; }
spoof_notice	{ return SPOOF_NOTICE; }
tkline_expire_notices { return TKLINE_EXPIRE_NOTICES; }
type		{ return TYPE; }
true_no_oper_flood { return TRUE_NO_OPER_FLOOD; }
umodes          { return T_UMODES; }
unkline		{ return UNKLINE; }
use_egd 	{ return USE_EGD; }
use_except	{ return USE_EXCEPT; }
use_invex	{ return USE_INVEX; }
use_knock	{ return USE_KNOCK; }
use_logging	{ return USE_LOGGING; }
use_whois_actually { return USE_WHOIS_ACTUALLY; }
throttle_time { return THROTTLE_TIME; }
user		{ return USER; } 
tkline		{ return TKLINE; } 
txline		{ return TXLINE; } 
tresv		{ return TRESV; } 
vhost	{ return VHOST; }
vhost6	{ return VHOST6; }
warn		{ return WARN; }
xline		{ return XLINE; }
yes		{ yylval.number = YES; return TBOOL; }

failed_oper_notice      { return FAILED_OPER_NOTICE; }
max_accept              { return MAX_ACCEPT; }
max_nick_changes        { return MAX_NICK_CHANGES; }
max_chans_per_user      { return MAX_CHANS_PER_USER; }
max_nick_time           { return MAX_NICK_TIME; }
anti_nick_flood         { return ANTI_NICK_FLOOD; }
anti_spam_exit_message_time { return ANTI_SPAM_EXIT_MESSAGE_TIME; }
ts_max_delta            { return TS_MAX_DELTA; }
ts_warn_delta           { return TS_WARN_DELTA; }
links_delay             { return LINKS_DELAY; }
kline_reason		{ return KLINE_REASON; }
kline_with_reason       { return KLINE_WITH_REASON; }
warn_no_nline           { return WARN_NO_NLINE; }

stats_e_disabled        { return STATS_E_DISABLED; }
stats_o_oper_only       { return STATS_O_OPER_ONLY; }
stats_k_oper_only	{ return STATS_K_OPER_ONLY; }
stats_i_oper_only	{ return STATS_I_OPER_ONLY; }
stats_P_oper_only	{ return STATS_P_OPER_ONLY; }
pace_wait               { return PACE_WAIT; }
pace_wait_simple	{ return PACE_WAIT_SIMPLE; }
knock_delay             { return KNOCK_DELAY; }
knock_delay_channel	{ return KNOCK_DELAY_CHANNEL; }
max_bans                { return MAX_BANS; }
modules                 { return MODULES; }
module                  { return MODULE; }
path                    { return PATH; }
max_targets             { return MAX_TARGETS; }

unxline			{ return T_UNXLINE; }
unresv			{ return T_UNRESV; }

oper_only_umodes        { return OPER_ONLY_UMODES; }
oper_umodes             { return OPER_UMODES; }
bots                    { return T_BOTS; }
cconn                   { return T_CCONN; }
deaf                    { return T_DEAF; }
debug                   { return T_DEBUG; }
full                    { return T_FULL; }
skill                   { return T_SKILL; }
nchange                 { return T_NCHANGE; }
rej                     { return T_REJ; }
unauth                  { return T_UNAUTH; }
spy                     { return T_SPY; }
external                { return T_EXTERNAL; }
operwall                { return T_OPERWALL; }
servnotice              { return T_SERVNOTICE; }
invisible               { return T_INVISIBLE; }
wallop                  { return T_WALLOP; }
callerid                { return T_CALLERID; }
softcallerid            { return T_SOFTCALLERID; }
drone                   { return T_DRONE; }
locops                  { return T_LOCOPS; }
topicburst		{ return TOPICBURST; }

weeks			{ return WEEKS; }
week			{ return WEEKS; }
days			{ return DAYS; }
day			{ return DAYS; }
hours			{ return HOURS; }
hour			{ return HOURS; }
minutes			{ return MINUTES; }
minute			{ return MINUTES; }
seconds			{ return SECONDS; }
second			{ return SECONDS; }

bytes			{ return BYTES; }
byte			{ return BYTES; }
kilobytes		{ return KBYTES; }
kilobyte		{ return KBYTES; }
kbytes			{ return KBYTES; }
kbyte			{ return KBYTES; }
kb			{ return KBYTES; }
megabytes		{ return MBYTES; }
megabyte		{ return MBYTES; }
mbytes			{ return MBYTES; }
mbyte			{ return MBYTES; }
mb			{ return MBYTES; }
gigabytes		{ return GBYTES; }
gigabyte		{ return GBYTES; }
gbytes			{ return GBYTES; }
gbyte			{ return GBYTES; }
gb			{ return GBYTES; }
terabytes		{ return TBYTES; }
terabyte		{ return TBYTES; }
tbytes			{ return TBYTES; }
tbyte			{ return TBYTES; }
tb			{ return TBYTES; }
\.\.                    { return TWODOTS; }

.		        { return yytext[0]; }
<<EOF>>     { if (ieof()) yyterminate(); }

%%

/* C-comment ignoring routine -kre*/
static void
ccomment(void)
{
  int c = 0;

  /* log(L_NOTICE, "got comment"); */
  while (1)
  {
    while ((c = input()) != '*' && c != EOF)
      if (c == '\n')
        ++lineno;

    if (c == '*')
    {
      while ((c = input()) == '*')
        /* Nothing */ ;
      if (c == '/')
        break;
      else if (c == '\n')
        ++lineno;
    }

    if (c == EOF)
    {
      YY_FATAL_ERROR("EOF in comment");
      /* XXX hack alert this disables
       * the stupid unused function warning
       * gcc generates 
       */
      if (1 == 0)
        yy_fatal_error("EOF in comment");
      break;
    }
  }
}

/* C-style .includes. This function will properly swap input conf buffers,
 * and lineno -kre */
static void
cinclude(void)
{
  char *p = NULL;

  if ((p = strchr(yytext, '<')) == NULL)
    *strchr(p = strchr(yytext, '"') + 1, '"') = '\0';
  else
    *strchr(++p, '>') = '\0';

  /* log(L_NOTICE, "got include %s!", c); */

  /* do stacking and co. */ 
  if (include_stack_ptr >= MAX_INCLUDE_DEPTH)
    ilog(L_ERROR, "Includes nested too deep in %s", p);
  else
  {
    FBFILE *tmp_fbfile_in = NULL;
    char filenamebuf[IRCD_BUFSIZE];

    if (*p == '/')  /* if it is an absolute path */
      snprintf(filenamebuf, sizeof(filenamebuf), "%s", p);
    else
      snprintf(filenamebuf, sizeof(filenamebuf), "%s/%s", ETCPATH, p);

    tmp_fbfile_in = fbopen(filenamebuf, "r");
    
    if (tmp_fbfile_in == NULL)
    {
      ilog(L_ERROR, "Unable to read configuration file '%s': %s",
           filenamebuf, strerror(errno));
      return;
    }

    lineno_stack[include_stack_ptr] = lineno;
    lineno = 1;
    inc_fbfile_in[include_stack_ptr] = conf_fbfile_in;
    strlcpy(conffile_stack[include_stack_ptr], conffilebuf, IRCD_BUFSIZE);
    include_stack[include_stack_ptr++] = YY_CURRENT_BUFFER;
    conf_fbfile_in = tmp_fbfile_in;
    snprintf(conffilebuf, sizeof(conffilebuf), "%s", filenamebuf);
    yy_switch_to_buffer(yy_create_buffer(yyin, YY_BUF_SIZE));
  }
}

/* This is function that will be called on EOF in conf file. It will
 * apropriately close conf if it not main conf and swap input buffers -kre
 * */
static int
ieof(void)
{
  /* log(L_NOTICE, "return from include stack!"); */
  if (include_stack_ptr)
    fbclose(conf_fbfile_in);
  if (--include_stack_ptr < 0)
  {
    /* log(L_NOTICE, "terminating lexer"); */
    /* We will now exit the lexer - restore init values if we get /rehash
     * later and reenter lexer -kre */
    include_stack_ptr = 0;
    lineno = 1;
    return 1;
  }

  /* switch buffer */
  /* log(L_NOTICE, "deleting include_stack_ptr=%d", include_stack_ptr); */
  yy_delete_buffer(YY_CURRENT_BUFFER);
  lineno = lineno_stack[include_stack_ptr];
  conf_fbfile_in = inc_fbfile_in[include_stack_ptr];
  strlcpy(conffilebuf, conffile_stack[include_stack_ptr], sizeof(conffilebuf)); 
  yy_switch_to_buffer(include_stack[include_stack_ptr]);

  return 0;
}
