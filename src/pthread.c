/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifdef __ANDROID__

#include <libcompat/pthread.h>
#include <signal.h>
#include <string.h>

/*
 * Workaround for pthread_cancel() in Android, using pthread_kill() instead, as
 * Android NDK does not support pthread_cancel().
 */

int pthread_setcanceltype(int type, int *oldtype) {
  if (oldtype)
    *oldtype = PTHREAD_CANCEL_DEFERRED;
  (void)type;
  return 0;
}

int pthread_setcancelstate(int state, int *oldstate) {
  if (oldstate)
    *oldstate = PTHREAD_CANCEL_ENABLE;
  (void)state;
  return 0;
}

void thread_exit_handler(int sig) {
  (void)sig;
  pthread_exit(0);
}

int set_thread_exit_handler(void) {
  struct sigaction actions;

  memset(&actions, 0, sizeof(actions));
  sigemptyset(&actions.sa_mask);
  actions.sa_flags = 0;
  actions.sa_handler = thread_exit_handler;

  return sigaction(SIGUSR1, &actions, NULL);
}

int pthread_cancel(pthread_t thread_id) {
  int status;

  status = set_thread_exit_handler();
  if (status == 0)
    status = pthread_kill(thread_id, SIGUSR1);

  return status;
}

int pthread_setconcurrency(int new_level) {
  (void)new_level;
  return 0;
}

int pthread_getconcurrency(void) {
  return 0;
}

int pthread_attr_getinheritsched(const pthread_attr_t *attr, int *inheritsched) {
  if (inheritsched)
    *inheritsched = PTHREAD_INHERIT_SCHED;
  (void)attr;
  return 0;
}

int pthread_attr_setinheritsched(pthread_attr_t *attr, int inheritsched) {
  (void)attr;
  (void)inheritsched;
  return 0;
}

#endif
