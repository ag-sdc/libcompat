/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifndef __COMPAT_PARAM_H__
#define __COMPAT_PARAM_H__

#ifdef __ANDROID__

#ifndef NBBY
#define NBBY 8
#endif

#ifndef MAXPATHLEN
#define MAXPATHLEN 4096
#endif

#ifndef MAXNAMELEN
#define MAXNAMELEN 256
#endif

#ifndef howmany
#define howmany(x, y) (((x) + ((y) - 1)) / (y))
#endif

#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#ifndef PAGEOFFSET
#define PAGEOFFSET (PAGESIZE - 1)
#endif

#ifndef PAGEMASK
#define PAGEMASK (~PAGEOFFSET)
#endif

#ifndef roundup
#define roundup(x, y) ((((x) + ((y) - 1)) / (y)) * (y))
#endif

#ifndef DEV_BSIZE
#define DEV_BSIZE 512
#endif

#ifndef DEV_BSHIFT
#define DEV_BSHIFT 9
#endif

#endif

#endif
