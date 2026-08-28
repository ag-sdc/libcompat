/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifdef __ANDROID__

#include <libcompat/mntent.h>
#include <stdio.h>
#include <string.h>

char *hasmntopt(const struct mntent *mnt, const char *opt) {
  char *o;
  size_t optlen;

  if (!mnt || !mnt->mnt_opts || !opt)
    return NULL;

  optlen = strlen(opt);
  o = mnt->mnt_opts;
  while ((o = strstr(o, opt)) != NULL) {
    if ((o == mnt->mnt_opts || *(o - 1) == ',') &&
        (o[optlen] == '\0' || o[optlen] == ',' || o[optlen] == '=')) {
      return o;
    }
    o += optlen;
  }
  return NULL;
}

int addmntent(FILE *fp, const struct mntent *mnt) {
  if (!fp || !mnt)
    return 1;
  return (fprintf(fp, "%s %s %s %s %d %d\n",
                  mnt->mnt_fsname ? mnt->mnt_fsname : "",
                  mnt->mnt_dir ? mnt->mnt_dir : "",
                  mnt->mnt_type ? mnt->mnt_type : "",
                  mnt->mnt_opts ? mnt->mnt_opts : "",
                  mnt->mnt_freq,
                  mnt->mnt_passno) < 0
              ? 1
              : 0);
}

#endif
