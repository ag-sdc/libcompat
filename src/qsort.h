/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifndef __COMPAT_QSORT_H__
#define __COMPAT_QSORT_H__

#ifdef __ANDROID__

#include <stddef.h>

void qsort_r(void *base, size_t nel, size_t width,
	     int (*compare)(const void *a, const void *b, void *context),
	     void *arg);

#endif

#endif
