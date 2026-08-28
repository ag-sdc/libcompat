/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifndef __COMPAT_MNTENT_H__
#define __COMPAT_MNTENT_H__

#ifdef __ANDROID__

#include <stdio.h>

struct mntent;

#ifdef __cplusplus
extern "C" {
#endif

char *hasmntopt(const struct mntent *mnt, const char *opt);
int addmntent(FILE *fp, const struct mntent *mnt);

#ifdef __cplusplus
}
#endif

#endif

#endif
