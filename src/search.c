/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifdef __ANDROID__

#include <libcompat/search.h>
#include <stdlib.h>
#include <string.h>

static ENTRY *htable = NULL;
static size_t htablesize = 0;

static unsigned long hash_string(const char *str) {
  unsigned long hash = 5381;
  int c;
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c;
  return hash;
}

int hcreate(size_t nel) {
  if (htable != NULL)
    return 0;
  if (nel == 0)
    nel = 16;
  htablesize = nel * 2 + 1;
  htable = (ENTRY *)calloc(htablesize, sizeof(ENTRY));
  return (htable != NULL) ? 1 : 0;
}

void hdestroy(void) {
  if (htable) {
    free(htable);
    htable = NULL;
    htablesize = 0;
  }
}

ENTRY *hsearch(ENTRY item, ACTION action) {
  if (htable == NULL || item.key == NULL)
    return NULL;

  unsigned long hash = hash_string(item.key);
  size_t idx = hash % htablesize;
  size_t start_idx = idx;

  while (htable[idx].key != NULL) {
    if (strcmp(htable[idx].key, item.key) == 0) {
      return &htable[idx];
    }
    idx = (idx + 1) % htablesize;
    if (idx == start_idx) {
      if (action == ENTER)
        return NULL;
      break;
    }
  }

  if (action == ENTER) {
    htable[idx] = item;
    return &htable[idx];
  }

  return NULL;
}

#endif
