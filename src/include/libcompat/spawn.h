/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifndef __COMPAT_SPAWN_H__
#define __COMPAT_SPAWN_H__

#ifdef __ANDROID__

#include <sys/types.h>
#include <sched.h>
#include <signal.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  short __flags;
  pid_t __pgrp;
  sigset_t __sd;
  sigset_t __ss;
  struct sched_param __sp;
  int __policy;
  int __pad[16];
} posix_spawnattr_t;

typedef struct {
  int __allocated;
  int __used;
  void *__actions;
  int __pad[16];
} posix_spawn_file_actions_t;

#define POSIX_SPAWN_RESETIDS 0x01
#define POSIX_SPAWN_SETPGROUP 0x02
#define POSIX_SPAWN_SETSIGDEF 0x04
#define POSIX_SPAWN_SETSIGMASK 0x08
#define POSIX_SPAWN_SETSCHEDPARAM 0x10
#define POSIX_SPAWN_SETSCHEDULER 0x20

int posix_spawn(pid_t *pid, const char *path,
                const posix_spawn_file_actions_t *file_actions,
                const posix_spawnattr_t *attrp,
                char *const argv[], char *const envp[]);

int posix_spawnp(pid_t *pid, const char *file,
                 const posix_spawn_file_actions_t *file_actions,
                 const posix_spawnattr_t *attrp,
                 char *const argv[], char *const envp[]);

int posix_spawnattr_init(posix_spawnattr_t *attr);
int posix_spawnattr_destroy(posix_spawnattr_t *attr);
int posix_spawnattr_getflags(const posix_spawnattr_t *attr, short *flags);
int posix_spawnattr_setflags(posix_spawnattr_t *attr, short flags);

int posix_spawn_file_actions_init(posix_spawn_file_actions_t *file_actions);
int posix_spawn_file_actions_destroy(posix_spawn_file_actions_t *file_actions);
int posix_spawn_file_actions_addopen(posix_spawn_file_actions_t *file_actions,
                                     int fd, const char *path, int oflag, mode_t mode);
int posix_spawn_file_actions_addclose(posix_spawn_file_actions_t *file_actions, int fd);
int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *file_actions, int fd, int newfd);

#ifdef __cplusplus
}
#endif

#endif

#endif
