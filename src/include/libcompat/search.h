/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifndef __COMPAT_SEARCH_H__
#define __COMPAT_SEARCH_H__

#ifdef __ANDROID__

#include <search.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

int hcreate(size_t nel);
void hdestroy(void);
ENTRY *hsearch(ENTRY item, ACTION action);

#ifdef __cplusplus
}
#endif

#endif

#endif
