/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 021110-1307, USA.
 */

#ifdef __ANDROID__

#include "getenv.h"
#include <stdlib.h>
#include <unistd.h>

#ifndef HAVE_SECURE_GETENV
char *secure_getenv(const char *name) {
#if defined(HAVE_ISSETUGID)
  if (issetugid())
    return NULL;
#else
  if (getuid() != geteuid() || getgid() != getegid())
    return NULL;
#endif
  return getenv(name);
}

#endif

#endif
