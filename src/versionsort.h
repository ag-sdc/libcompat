/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */                                                                            \

#ifndef __COMPAT_VERSIONSORT_H__
#define __COMPAT_VERSIONSORT_H__

#ifdef __ANDROID__

#include <dirent.h>

int versionsort(const struct dirent **a, const struct dirent **b);

#endif

#endif
