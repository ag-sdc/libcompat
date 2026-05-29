/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifndef __COMPAT_PTHREAD_H__
#define __COMPAT_PTHREAD_H__

#ifdef __ANDROID__

#include <pthread.h>

#define PTHREAD_CANCELED ((void *)-1)

#define PTHREAD_CANCEL_DEFERRED 0
#define PTHREAD_CANCEL_ASYNCHRONOUS 0
#define PTHREAD_CANCEL_ENABLE 0
#define PTHREAD_CANCEL_DISABLE 0

int pthread_setcanceltype(int type, int *oldtype);
int pthread_setcancelstate(int state, int *oldstate);
int pthread_cancel(pthread_t thread_id);

int set_thread_exit_handler();
void thread_exit_handler(int sig);

#endif

#endif
