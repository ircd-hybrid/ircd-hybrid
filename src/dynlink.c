/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  dynlink.c: A module loader.
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
 * $Id$
 *
 */
#include "stdinc.h"
#include "tools.h"
#include "irc_string.h"
#include "modules.h"
#include "s_log.h"
#include "client.h"
#include "send.h"

#ifndef RTLD_NOW
#define RTLD_NOW RTLD_LAZY /* openbsd deficiency */
#endif

#if defined(HAVE_DLINFO) && defined(HAVE_LINK_H)
# include <link.h>
#endif

extern dlink_list mod_list;

static char unknown_ver[] = "<unknown>";

/* This file contains the core functions to use dynamic libraries.
 * -TimeMr14C
 */

#if !defined(HAVE_SHL_LOAD) && !defined(HAVE_DLFUNC)
/*
 * Fake dlfunc(3) if we don't have it, cause it's happy.
 */
typedef void (*__function_p)(void);

static __function_p
dlfunc(void *myHandle, const char *functionName)
{
  /* XXX This is not guaranteed to work, but with
   * traditional dl*(3), it is the best we can do.
   * -jmallett
   */
  void *symbolp;

  symbolp = dlsym(myHandle, functionName);
  return((__function_p)(uintptr_t)symbolp);
}
#endif

#ifdef HAVE_MACH_O_DYLD_H
/*
** jmallett's dl*(3) shims for NSModule(3) systems.
*/
#include <mach-o/dyld.h>

#ifndef HAVE_DLOPEN
#ifndef	RTLD_LAZY
#define RTLD_LAZY 2185 /* built-in dl*(3) don't care */
#endif

void undefinedErrorHandler(const char *);
NSModule multipleErrorHandler(NSSymbol, NSModule, NSModule);
void linkEditErrorHandler(NSLinkEditErrors, int, const char *, const char *);
char *dlerror(void);
void *dlopen(char *, int);
int dlclose(void *);
void *dlsym(void *, char *);

static int firstLoad = TRUE;
static int myDlError;
static const char *myErrorTable[] =
{
  "Loading file as object failed\n",
  "Loading file as object succeeded\n",
  "Not a valid shared object\n",
  "Architecture of object invalid on this architecture\n",
  "Invalid or corrupt image\n",
  "Could not access object\n",
  "NSCreateObjectFileImageFromFile failed\n",
  NULL
};

void
undefinedErrorHandler(const char *symbolName)
{
  sendto_realops_flags(UMODE_ALL, L_ALL, "Undefined symbol: %s", symbolName);
  ilog(L_WARN, "Undefined symbol: %s", symbolName);
  return;
}

NSModule
multipleErrorHandler(NSSymbol s, NSModule old, NSModule new)
{
  /* XXX
  ** This results in substantial leaking of memory... Should free one
  ** module, maybe?
  */
  sendto_realops_flags(UMODE_ALL, L_ALL, "Symbol `%s' found in `%s' and `%s'",
                       NSNameOfSymbol(s), NSNameOfModule(old), NSNameOfModule(new));
  ilog(L_WARN, "Symbol `%s' found in `%s' and `%s'", NSNameOfSymbol(s),
       NSNameOfModule(old), NSNameOfModule(new));
  /* We return which module should be considered valid, I believe */
  return(new);
}

void
linkEditErrorHandler(NSLinkEditErrors errorClass, int errnum,
		     const char *fileName, const char *errorString)
{
  sendto_realops_flags(UMODE_ALL, L_ALL, "Link editor error: %s for %s",
                       errorString, fileName);
  ilog(L_WARN, "Link editor error: %s for %s", errorString, fileName);
  return;
}

char *
dlerror(void)
{
  return(myDlError == NSObjectFileImageSuccess ? NULL : myErrorTable[myDlError % 7]);
}

void *
dlopen(char *filename, int unused)
{
  NSObjectFileImage myImage;
  NSModule myModule;

  if (firstLoad)
  {
    /* If we are loading our first symbol (huzzah!) we should go ahead
     * and install link editor error handling!
     */
    NSLinkEditErrorHandlers linkEditorErrorHandlers;

    linkEditorErrorHandlers.undefined = undefinedErrorHandler;
    linkEditorErrorHandlers.multiple  = multipleErrorHandler;
    linkEditorErrorHandlers.linkEdit  = linkEditErrorHandler;
    NSInstallLinkEditErrorHandlers(&linkEditorErrorHandlers);
    firstLoad = FALSE;
  }

  myDlError = NSCreateObjectFileImageFromFile(filename, &myImage);

  if (myDlError != NSObjectFileImageSuccess)
    return(NULL);

  myModule = NSLinkModule(myImage, filename, NSLINKMODULE_OPTION_PRIVATE);
  return((void *)myModule);
}

int
dlclose(void *myModule)
{
  NSUnLinkModule(myModule, FALSE);
  return(0);
}

void *
dlsym(void *myModule, char *mySymbolName)
{
  NSSymbol mySymbol;

  mySymbol = NSLookupSymbolInModule((NSModule)myModule, mySymbolName);
  return NSAddressOfSymbol(mySymbol);
}
#endif
#endif

/* unload_one_module()
 *
 * inputs	- name of module to unload
 *		- 1 to say modules unloaded, 0 to not
 * output	- 0 if successful, -1 if error
 * side effects	- module is unloaded
 */
int
unload_one_module(char *name, int warn)
{
  dlink_node *ptr = NULL;
  struct module *modp = NULL;

  if ((ptr = findmodule_byname(name)) == NULL) 
    return -1;

  modp = ptr->data;

  if (modp->modremove)
    (*modp->modremove)();

#ifdef HAVE_SHL_LOAD
    /* shl_* and friends have a slightly different format than dl*. But it does not
     * require creation of a totally new modules.c, instead proper usage of
     * defines solve this case. -TimeMr14C
     */
  shl_unload((shl_t) & (modp->handle));
#else
  /* We use FreeBSD's dlfunc(3) interface, or fake it as we
   * used to here if it isn't there.  The interface should
   * be standardised some day, and so it eventually will be
   * providing something guaranteed to do the right thing here.
   *          -jmallett
   */
  dlclose(modp->handle);
#endif
  assert(dlink_list_length(&mod_list) > 0);
  dlinkDelete(ptr, &mod_list);
  MyFree(modp->name);
  MyFree(modp);

  if (warn == 1)
  {
    ilog(L_INFO, "Module %s unloaded", name);
    sendto_realops_flags(UMODE_ALL, L_ALL, "Module %s unloaded", name);
  }

  return 0;
}

/* load_a_module()
 *
 * inputs	- path name of module, int to notice, int of core
 * output	- -1 if error 0 if success
 * side effects - loads a module if successful
 */
int
load_a_module(char *path, int warn, int core)
{
#ifdef HAVE_DLINFO
  struct link_map *map;
#endif
#ifdef HAVE_SHL_LOAD
  shl_t tmpptr;
#else
  void *tmpptr = NULL;
#endif
  void *addr = NULL;
  char *mod_basename;
  void (*initfunc)(void) = NULL;
  void (*mod_deinit)(void) = NULL;
  char **verp;
  char *ver;
  struct module *modp;

  mod_basename = basename(path);

  if (findmodule_byname(mod_basename) != NULL)
    return(1);

#ifdef HAVE_SHL_LOAD
  tmpptr = shl_load(path, BIND_IMMEDIATE, NULL);
#else
  tmpptr = dlopen(path, RTLD_NOW);
#endif

  if (tmpptr == NULL)
  {
#ifdef HAVE_SHL_LOAD
    const char *err = strerror(errno);
#else
    const char *err = dlerror();
#endif
    sendto_realops_flags(UMODE_ALL, L_ALL, "Error loading module %s: %s",
                         mod_basename, err);
    ilog(L_WARN, "Error loading module %s: %s", mod_basename, err);
    
    return(-1);
  }

#ifdef HAVE_SHL_LOAD
  if (shl_findsym(&tmpptr, "_modinit", TYPE_UNDEFINED, (void *)&initfunc) == -1)
  {
    if (shl_findsym(&tmpptr, "__modinit", TYPE_UNDEFINED, (void *)&initfunc) == -1)
    {
      ilog(L_WARN, "Module %s has no _modinit() function", mod_basename);
      sendto_realops_flags(UMODE_ALL, L_ALL, "Module %s has no _modinit() function",
                           mod_basename);
      shl_unload(tmpptr);
      return(-1);
    }
  }

  if (shl_findsym(&tmpptr, "_moddeinit", TYPE_UNDEFINED, (void *)&mod_deinit) == -1)
  {
    if (shl_findsym(&tmpptr, "__moddeinit", TYPE_UNDEFINED, (void *)&mod_deinit) == -1)
    {
      ilog(L_WARN, "Module %s has no _moddeinit() function", mod_basename);
      sendto_realops_flags(UMODE_ALL, L_ALL, "Module %s has no _moddeinit() function",
                           mod_basename);
      /* this is a soft error.  we're allowed not to have one, i guess.
       * (judging by the code in unload_one_module() */
      mod_deinit = NULL;
    }
  }

  if (shl_findsym(&tmpptr, "_version", TYPE_UNDEFINED, &verp) == -1)
  {
    if (shl_findsym(&tmpptr, "__version", TYPE_UNDEFINED, &verp) == -1)
      ver = unknown_ver;
    else
      ver = *verp;
  }
  else
    ver = *verp;
#else
  if ((initfunc = (void(*)(void))dlfunc(tmpptr, "_modinit")) == NULL &&
      /* Only for compatibility, because some systems have underscore
       * prepended symbol names */
      (initfunc = (void(*)(void))dlfunc(tmpptr, "__modinit")) == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "Module %s has no _modinit() function",
                         mod_basename);
    ilog(L_WARN, "Module %s has no _modinit() function", mod_basename);
    dlclose(tmpptr);
    return(-1);
  }

  mod_deinit = (void(*)(void))dlfunc(tmpptr, "_moddeinit");

  if (mod_deinit == NULL && (mod_deinit = (void(*)(void))dlfunc(tmpptr, "__moddeinit")) == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "Module %s has no _moddeinit() function",
                         mod_basename);
    ilog(L_WARN, "Module %s has no _moddeinit() function", mod_basename);
    /* blah blah soft error, see above. */
    mod_deinit = NULL;
  }

  verp = (char **)dlsym(tmpptr, "_version");

  if (verp == NULL && (verp = (char **)dlsym(tmpptr, "__version")) == NULL)
    ver = unknown_ver;
  else
    ver = *verp;
#endif

  modp            = MyMalloc(sizeof(struct module));
#ifdef HAVE_DLINFO
  dlinfo(tmpptr, RTLD_DI_LINKMAP, &map);
  if (map != NULL)
    addr = (void *)map->l_addr;
  else
#endif
    addr = tmpptr;

  modp->handle    = tmpptr;
  modp->address   = addr;
  modp->version   = ver;
  modp->core      = core;
  modp->modremove = mod_deinit;

  DupString(modp->name, mod_basename);
  dlinkAdd(modp, &modp->node, &mod_list);

  initfunc();

  if (warn == 1)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Module %s [version: %s] loaded at %p",
                         mod_basename, ver, addr);
    ilog(L_WARN, "Module %s [version: %s] loaded at %p",
         mod_basename, ver, addr);
  }

  return(0);
}
