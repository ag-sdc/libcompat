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

#include <stdlib.h>
#include "qsort.h"

struct qsort_r_context {
	int (*compare)(const void *a, const void *b, void *context);
	void *arg;
};

#if __STDC_VERSION__ < 201112L || defined(__STDC_NO_THREADS__)
#define _Thread_local __thread
#endif

static _Thread_local struct qsort_r_context *qsort_r_ctx = NULL;

static int qsort_r_stub_compare(const void *a, const void *b)
{
	return qsort_r_ctx->compare(a, b, qsort_r_ctx->arg);
}

void qsort_r(void *base, size_t nel, size_t width,
	     int (*compare)(const void *a, const void *b, void *context),
	     void *arg)
{
	struct qsort_r_context ctx;
	struct qsort_r_context *old_ctx;

	if (nel == 0)
		return;

	ctx.compare = compare;
	ctx.arg = arg;
	old_ctx = qsort_r_ctx;
	qsort_r_ctx = &ctx;
	qsort(base, nel, width, qsort_r_stub_compare);

	/* Restore the old context after qsort is finished. */
	qsort_r_ctx = old_ctx;
}
