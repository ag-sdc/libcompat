/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifdef __ANDROID__

#include <libcompat/memory.h>
#include <stdlib.h>
#include <unistd.h>

void *valloc(size_t size) {
  void *ptr = NULL;
  size_t pagesize = sysconf(_SC_PAGESIZE);
  if (pagesize == 0)
    pagesize = 4096;
  if (posix_memalign(&ptr, pagesize, size) != 0)
    return NULL;
  return ptr;
}

void *pvalloc(size_t size) {
  size_t pagesize = sysconf(_SC_PAGESIZE);
  if (pagesize == 0)
    pagesize = 4096;
  size = (size + pagesize - 1) & ~(pagesize - 1);
  return valloc(size);
}

#endif
