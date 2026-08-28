/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifndef __COMPAT_EXECINFO_H__
#define __COMPAT_EXECINFO_H__

#ifdef __ANDROID__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline int backtrace(void **buffer, int size) {
  (void)buffer;
  (void)size;
  return 0;
}

static inline char **backtrace_symbols(void *const *buffer, int size) {
  (void)buffer;
  (void)size;
  return NULL;
}

static inline void backtrace_symbols_fd(void *const *buffer, int size, int fd) {
  (void)buffer;
  (void)size;
  (void)fd;
}

#ifdef __cplusplus
}
#endif

#endif

#endif
