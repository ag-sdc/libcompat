/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifndef __COMPAT_PROGNAME_H__
#define __COMPAT_PROGNAME_H__

#ifndef HAVE_PROGRAM_INVOCATION_SHORT_NAME
#include <stdlib.h>
#define program_invocation_short_name getprogname()
#endif

#endif
