/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  csvlib.c - set of functions to deal with csv type of conf files
 *
 *  Copyright (C) 2003 by Diane Bruce, Stuart Walsh
 *  Use it anywhere you like, if you like it buy us a beer.
 *  If it's broken, don't bother us with the lawyers.
 *
 *  $Id$
 */

#include "config.h"
#include "stdinc.h"
#include "list.h"
#include "log.h"
#include "conf.h"
#include "hostmask.h"
#include "client.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "memory.h"
#include "send.h"
#include "resv.h"
#include "s_serv.h"

/* Fix "statement not reached" warnings on Sun WorkShop C */
#ifdef __SUNPRO_C
#   pragma error_messages(off, E_STATEMENT_NOT_REACHED)
#endif


static void parse_csv_line(char *, ...);
static int write_csv_line(FILE *, const char *, ...);
static int flush_write(struct Client *, FILE *, FILE *, 
                       const char *, const char *);
static char *getfield(char *);

int
find_and_delete_temporary(const char *user, const char *host, int type)
{
  struct irc_ssaddr iphost, *piphost;
  struct AccessItem *aconf;
  int t;

  if ((t = parse_netmask(host, &iphost, NULL)) != HM_HOST)
  {
#ifdef IPV6
    if (t == HM_IPV6)
      t = AF_INET6;
    else
#endif
      t = AF_INET;
    piphost = &iphost;
  }
  else
  {
    t = 0;
    piphost = NULL;
  }

  if ((aconf = find_conf_by_address(host, piphost, type, t, user, NULL, 0)))
  {
    if (IsConfTemporary(aconf))
    {
      delete_one_address_conf(host, aconf);
      return 1;
    }
  }

  return 0;
}

/* parse_csv_file()
 *
 * inputs	- FILE pointer
 * 		- type of conf to parse
 * output	- none
 * side effects	-
 */
void
parse_csv_file(FILE *file, ConfType conf_type)
{
  struct ConfItem *conf;
  struct AccessItem *aconf;
  struct MatchItem *match_item;
  char  *name_field=NULL;
  char  *user_field=NULL;
  char  *reason_field=NULL;
  char  *oper_reason=NULL;
  char  *host_field=NULL;
  char  line[IRCD_BUFSIZE];
  char  *p;

  while (fgets(line, sizeof(line), file) != NULL)
  {
    if ((p = strchr(line, '\n')) != NULL)
      *p = '\0';

    if ((line[0] == '\0') || (line[0] == '#'))
      continue;

    switch(conf_type)
    {
    case KLINE_TYPE:
      parse_csv_line(line, &user_field, &host_field, &reason_field, NULL);

      find_and_delete_temporary(user_field, host_field, CONF_KLINE);

      conf = make_conf_item(KLINE_TYPE);
      aconf = map_to_conf(conf);

      if (host_field != NULL)
	DupString(aconf->host, host_field);
      if (reason_field != NULL)
	DupString(aconf->reason, reason_field);
      if (user_field != NULL)
	DupString(aconf->user, user_field);
      if (aconf->host != NULL)
	add_conf_by_address(CONF_KLINE, aconf);
      break;
    case DLINE_TYPE:
      parse_csv_line(line, &host_field, &reason_field, NULL);

      if (host_field && parse_netmask(host_field, NULL, NULL) != HM_HOST)
      {
        find_and_delete_temporary(NULL, host_field, CONF_DLINE);

        aconf = map_to_conf(make_conf_item(DLINE_TYPE));
        DupString(aconf->host, host_field);

        if (reason_field != NULL)
          DupString(aconf->reason, reason_field);
        else
          DupString(aconf->reason, "No reason");
        add_conf_by_address(CONF_DLINE, aconf);
      }

      break;

    case XLINE_TYPE:
      parse_csv_line(line, &name_field, &reason_field, &oper_reason, NULL);
      conf = make_conf_item(XLINE_TYPE);
      match_item = (struct MatchItem *)map_to_conf(conf);
      if (name_field != NULL)
	DupString(conf->name, name_field);
      if (reason_field != NULL)
	DupString(match_item->reason, reason_field);
      break;
    case CRESV_TYPE:
      parse_csv_line(line, &name_field, &reason_field, NULL);
      (void)create_channel_resv(name_field, reason_field, 0);
      break;

    case NRESV_TYPE:
      parse_csv_line(line, &name_field, &reason_field, NULL);
      (void)create_nick_resv(name_field, reason_field, 0);
      break;

    case GLINE_TYPE:
    case CONF_TYPE:
    case OPER_TYPE:
    case CLIENT_TYPE:
    case SERVER_TYPE:
    case CLUSTER_TYPE:
    case HUB_TYPE:
    case LEAF_TYPE:
    case ULINE_TYPE:
    case EXEMPTDLINE_TYPE:
    case CLASS_TYPE:
    default:
      break;
    }
  }
}

/*
 * parse_csv_line()
 *
 * inputs	- pointer to line to parse
 * output	-
 * side effects -
 */

static void
parse_csv_line(char *line, ...)
{
  va_list args;
  char **dest;
  char *field = NULL;

  va_start(args, line);

  for (; ;)
  {
    dest = va_arg(args, char **);
    if ((dest == NULL) || ((field = getfield(field ? NULL : line)) == NULL))
    {
      va_end(args);
      return;
    }
    *dest = field;
  }
}

/* write_conf_line()
 *
 * inputs       - pointer to struct AccessItem
 *		- string current_date (small date)
 *              - time_t cur_time
 * output       - NONE
 * side effects - This function takes care of
 *                finding right conf file, writing
 *                the right lines to this file, 
 *                notifying the oper that their kline/dline etc. is in place
 *                notifying the opers on the server about the k/d etc. line
 *                
 * - Dianora
 */
void 
write_conf_line(struct Client *source_p, struct ConfItem *conf,
		const char *current_date, time_t cur_time)
{
  FILE *out;
  const char *filename, *from, *to;
  struct AccessItem *aconf;
  struct MatchItem *xconf;
  struct ResvChannel *cresv_p=NULL;
  struct MatchItem *nresv_p=NULL;
  ConfType type;

  type = conf->type;
  filename = get_conf_name(type);

  if (!MyConnect(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

  if ((out = fopen(filename, "a")) == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "*** Problem opening %s ", filename);
    return;
  }

  switch(type)
  {
  case KLINE_TYPE:
    aconf = (struct AccessItem *)map_to_conf(conf);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s added K-Line for [%s@%s] [%s]",
                         get_oper_name(source_p),
			 aconf->user, aconf->host, aconf->reason);
    sendto_one(source_p, ":%s NOTICE %s :Added K-Line [%s@%s]",
               from, to, aconf->user, aconf->host);
    ilog(LOG_TYPE_KLINE, "%s added K-Line for [%s@%s] [%s]",
         source_p->name, aconf->user, aconf->host, aconf->reason);
    write_csv_line(out, "%s%s%s%s%s%s%d",
		   aconf->user, aconf->host,
		   aconf->reason, aconf->oper_reason, current_date,
		   get_oper_name(source_p), cur_time);
    break;
  case DLINE_TYPE:
    aconf = (struct AccessItem *)map_to_conf(conf);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s added D-Line for [%s] [%s]",
                         get_oper_name(source_p), aconf->host, aconf->reason);
    sendto_one(source_p, ":%s NOTICE %s :Added D-Line [%s] to %s",
               from, to, aconf->host, filename);
    ilog(LOG_TYPE_DLINE, "%s added D-Line for [%s] [%s]",
         get_oper_name(source_p), aconf->host, aconf->reason);
    write_csv_line(out, "%s%s%s%s%s%d",
		   aconf->host, aconf->reason, aconf->oper_reason, 
		   current_date,
		   get_oper_name(source_p), cur_time);
    break;

  case XLINE_TYPE:
    xconf = (struct MatchItem *)map_to_conf(conf);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s added X-Line for [%s] [%s]",
                         get_oper_name(source_p), conf->name,
			 xconf->reason);
    sendto_one(source_p,
	       ":%s NOTICE %s :Added X-Line [%s] [%d] [%s] to %s",
               from, to, conf->name, 
	       xconf->action, xconf->reason, filename);
    ilog(LOG_TYPE_IRCD, "%s added X-Line for [%s] [%s]",
         get_oper_name(source_p), conf->name, xconf->reason);
    write_csv_line(out, "%s%s%s%s%s%d",
		   conf->name, xconf->reason, xconf->oper_reason,
		   current_date, get_oper_name(source_p), cur_time);
    break;
  case CRESV_TYPE:
    cresv_p = (struct ResvChannel *)map_to_conf(conf);

    write_csv_line(out, "%s%s",
		   cresv_p->name, cresv_p->reason);
    break;

  case NRESV_TYPE:
    nresv_p = (struct MatchItem *)map_to_conf(conf);

    write_csv_line(out, "%s%s",
		   conf->name, nresv_p->reason);
    break;

  default:
    fclose(out);
    return;
  }

  fclose(out);
}

/*
 * write_csv_line()
 *
 * inputs	- pointer to FILE *
 *		- formatted string
 * output	-
 * side effects - single line is written to csv conf file
 */
static int
write_csv_line(FILE *out, const char *format, ...)
{
  char c;
  size_t bytes = 0;
  va_list args;
  char tmp[1024];
  char *str = tmp;
  const char *null_string = "";

  if (out == NULL)
    return(0);

  va_start(args, format);

  while ((c = *format++))
  {
    if (c == '%')
    {
      c = *format++;
      if (c == 's')
      {
	const char *p1 = va_arg(args, const char *);
	if (p1 == NULL)
	  p1 = null_string;
	*str++ = '\"';
	++bytes;
	while (*p1 != '\0')
	{
	  *str++ = *p1++;
	  ++bytes;
        }
	*str++ = '\"';
	*str++ = ',';
	  
	bytes += 2;
	continue;
      }
      if (c == 'c')
      {
	*str++ = '\"';
	++bytes;
	*str++ = (char) va_arg(args, int);
	++bytes;
	*str++ = '\"';
	*str++ = ',';

	bytes += 2;
	continue;
      }

      if (c == 'd')
      {
	int v = va_arg(args, int);
	char t[40];
	char *p=t;

	while (v > 10)
        {
	  *p++ = (v % 10) + '0';
	  v = v/10;
	}
	*p++ = (v % 10) + '0';

        *str++ = '\"';
        ++bytes;
	while (p != t)
	{
	  *str++ = *--p;
	  ++bytes;
	}

        *str++ = '\"';
	*str++ = ',';
	bytes += 2;
	continue;
      }
      if (c != '%')
      {
	int ret;
	
	format -= 2;
	ret = vsprintf(str, format, args);
	str += ret;
	bytes += ret;
	*str++ = ',';

	++bytes;
	break;
      }
    }
    *str++ = c;
    ++bytes;
  }

  if (*(str-1) == ',')
  {
    *(str-1) = '\n';
    *str = '\0';
  }
  else
  {
    *str++ = '\n';
    ++bytes;
    *str = '\0';
  }

  va_end(args);
  str = tmp;
  fputs(str, out);

  return(bytes);
}

/*
 * getfield
 *
 * inputs	- input buffer
 * output	- next field
 * side effects	- field breakup for ircd.conf file.
 */
static char *
getfield(char *newline)
{
  static char *line = NULL;
  char *end, *field;
        
  if (newline != NULL)
    line = newline;

  if (line == NULL)
    return(NULL);

  field = line;

  /* skip everything that's not a starting quote */
  for(;;)
  {
    if (*field == '\0')
      return(NULL);
    else if (*field == '"')
      break;
    ++field;
  }

  /* skip over the beginning " */
  end = ++field;
  
  for (;;)
  {
    /* At end of string, mark it as end and return */
    if ((*end == '\0') || (*end == '\n'))
    {
      line = NULL;
      return(NULL);
    }
    else if (*end == '\\')      /* found escape character ? */
    {
      end++;
    }
    else if (*end == '"')	/* found terminating " */
    {
      *end++ = '\0';
      line = end;
      return(field);
    }

    end++;
  }

  return (NULL);
}

/* remove_conf_line()
 *
 * inputs	- type of kline to remove
 *		- pointer to oper removing
 *		- pat1 pat2 patterns to match
 * output	- -1 if unsuccessful 0 if no change 1 if change
 * side effects	-
 */
int
remove_conf_line(ConfType type, struct Client *source_p, const char *pat1, const char *pat2)
{
  const char *filename;
  FILE *in, *out;
  int pairme=0;
  char buf[IRCD_BUFSIZE], buff[IRCD_BUFSIZE], temppath[IRCD_BUFSIZE];
  char *found1;
  char *found2;
  int oldumask;

  filename = get_conf_name(type);

  if ((in = fopen(filename, "r")) == NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Cannot open %s", me.name,
               source_p->name, filename);
    return -1;
  }

  ircsprintf(temppath, "%s.tmp", filename);
  oldumask = umask(0);

  if ((out = fopen(temppath, "w")) == NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Cannot open %s", me.name,
	       source_p->name, temppath);
    fclose(in);
    umask(oldumask);
    return -1;
  }

  umask(oldumask);
  oldumask = umask(0);

  while (fgets(buf, sizeof(buf), in) != NULL) 
  {
    if ((*buf == '\0') || (*buf == '#'))
    {
      if (flush_write(source_p, in, out, buf, temppath) < 0)
	return -1;
    }
    
    /* Keep copy of original line, getfield trashes line as it goes */
    strlcpy(buff, buf, sizeof(buff));

    if ((found1 = getfield(buff)) == NULL)
    {
      if (flush_write(source_p, in, out, buf, temppath) < 0)
	return -1;
      continue;
    }

    if (pat2 != NULL)
    {
      if ((found2 = getfield(NULL)) == NULL)
      {
	if (flush_write(source_p, in, out, buf, temppath) < 0)
	  return -1;
	continue;
      }

      if (!irccmp(pat1, found1) && !irccmp(pat2, found2))
      {
	pairme = 1;
	continue;
      }
      else
      {
	if(flush_write(source_p, in, out, buf, temppath) < 0)
	  return -1;
	continue;
      }
    }
    else
    {
      if (!irccmp(pat1, found1))
      {
	pairme = 1;
	continue;
      }
      else
      {
	if(flush_write(source_p, in, out, buf, temppath) < 0)
	  return -1;
	continue;
      }
    }
  }

  fclose(in);
  fclose(out);

/* The result of the rename should be checked too... oh well */
/* If there was an error on a write above, then its been reported
 * and I am not going to trash the original kline /conf file
 */

  if (pairme == 0)
  {
    if(temppath != NULL)
      (void)unlink(temppath);
    return 0;
  }
  else
  {
    (void)rename(temppath, filename);

    /* XXX
     * This is a very inefficient way of removing a kline/xline etc.
     * This next function call forces a complete re-read of all conf
     * files, instead of a re-read of the kline/dline etc. files modified
     * But, consider how often an /quote unkline etc. is done compared
     * to how often a /quote kline is done. Its not a biggie in
     * the grand scheme of things. If it does become a biggie,
     * we will rewrite it - Dianora
     */

    rehash(0);
    return 1;
  }
}

/*
 * flush_write()
 *
 * inputs       - pointer to client structure of oper requesting unkline
 *		- in is the input file descriptor
 *              - out is the output file descriptor
 *              - buf is the buffer to write
 *              - ntowrite is the expected number of character to be written
 *              - temppath is the temporary file name to be written
 * output       - -1 for error on write
 *              - 0 for ok
 * side effects - if successful, the buf is written to output file
 *                if a write failure happesn, and the file pointed to
 *                by temppath, if its non NULL, is removed.
 *
 * The idea here is, to be as robust as possible when writing to the 
 * kline file.
 *
 * -Dianora
 */
static int
flush_write(struct Client *source_p, FILE *in, FILE* out, 
            const char *buf, const char *temppath)
{
  int error_on_write = fputs(buf, out) < 0 ? (-1) : (0);

  if (error_on_write)
  {
    sendto_one(source_p,":%s NOTICE %s :Unable to write to %s aborting",
	       me.name, source_p->name, temppath);
    if(temppath != NULL)
      (void)unlink(temppath);
    fclose(in);
    fclose(out);
  }

  return (error_on_write);
}
