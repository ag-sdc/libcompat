/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifndef __COMPAT_GETENV_H__
#define __COMPAT_GETENV_H__

#ifdef __ANDROID__

#ifndef HAVE_SECURE_GETENV
char *secure_getenv(const char *name);
#endif

#endif

#endif
