/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifndef __COMPAT_MEMORY_H__
#define __COMPAT_MEMORY_H__

#ifdef __ANDROID__

#include <stdlib.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void *valloc(size_t size);
void *pvalloc(size_t size);

#ifdef __cplusplus
}
#endif

#endif

#endif
