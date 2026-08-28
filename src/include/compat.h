/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifndef __COMPAT_H__
#define __COMPAT_H__

#ifdef __ANDROID__

#include <libcompat/pthread.h>
#include <libcompat/getenv.h>
#include <libcompat/progname.h>
#include <libcompat/qsort.h>
#include <libcompat/strverscmp.h>
#include <libcompat/versionsort.h>
#include <libcompat/mntent.h>
#include <libcompat/param.h>
#include <libcompat/memory.h>

#endif

#endif
