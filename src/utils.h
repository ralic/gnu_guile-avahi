/* Guile-Avahi --- Guile bindings for Avahi.
   Copyright (C) 2007  Ludovic Court�s <ludovic.courtes@laas.fr>

   Guile-Avahi is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   Guile-Avahi is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with Guile-Avahi; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA  */

#ifndef GUILE_AVAHI_UTILS_H
#define GUILE_AVAHI_UTILS_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <libguile.h>


/* Compiler twiddling.  */

#ifdef __GNUC__
# define EXPECT    __builtin_expect
# define NO_RETURN __attribute__ ((__noreturn__))
#else
# define EXPECT(_expr, _value) (_expr)
# define NO_RETURN
#endif

#define EXPECT_TRUE(_expr)  EXPECT ((_expr), 1)
#define EXPECT_FALSE(_expr) EXPECT ((_expr), 0)


/* Avahi helpers.  */

#include <avahi-common/watch.h>
#include <avahi-client/client.h>

SCM_API SCM scm_from_avahi_watch_events (AvahiWatchEvent events);
SCM_API AvahiWatchEvent scm_to_avahi_watch_events (SCM events, int pos,
						   const char *func_name);
SCM_API AvahiClientFlags scm_to_avahi_client_flags (SCM flags, int pos,
						    const char *func_name);

#endif

/* arch-tag: 2cd14488-a545-43e4-8991-7c25b048fd72
 */
