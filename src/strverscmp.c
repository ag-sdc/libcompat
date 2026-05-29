/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 021110-1307, USA.
 */

#ifdef __ANDROID__

#include <ctype.h>
#include <libcompat/strverscmp.h>
#include <string.h>

/*
 * GNU strverscmp implementation
 * Compares strings handling version numbers appropriately.
 */
int strverscmp(const char *l0, const char *r0) {
  const unsigned char *l = (const void *)l0;
  const unsigned char *r = (const void *)r0;
  size_t i, dp, j;
  int z = 1;

  for (dp = i = 0; l[i] == r[i]; i++) {
    int c = l[i];
    if (!c)
      return 0;
    if (!isdigit(c))
      dp = i + 1, z = 1;
    else if (c != '0')
      z = 0;
  }

  if (l[dp] != '0' && r[dp] != '0') {
    for (j = i; isdigit(l[j]); j++)
      if (!isdigit(r[j]))
        return 1;
    if (isdigit(r[j]))
      return -1;
  } else if (z && dp < i && (isdigit(l[i]) || isdigit(r[i]))) {
    return (unsigned char)(l[i] - '0') - (unsigned char)(r[i] - '0');
  }

  return l[i] - r[i];
}

#endif
