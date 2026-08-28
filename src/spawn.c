/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifdef __ANDROID__

#include <libcompat/spawn.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>

int posix_spawnattr_init(posix_spawnattr_t *attr) {
  if (!attr) return EINVAL;
  attr->__flags = 0;
  return 0;
}

int posix_spawnattr_destroy(posix_spawnattr_t *attr) {
  (void)attr;
  return 0;
}

int posix_spawnattr_getflags(const posix_spawnattr_t *attr, short *flags) {
  if (!attr || !flags) return EINVAL;
  *flags = attr->__flags;
  return 0;
}

int posix_spawnattr_setflags(posix_spawnattr_t *attr, short flags) {
  if (!attr) return EINVAL;
  attr->__flags = flags;
  return 0;
}

int posix_spawn_file_actions_init(posix_spawn_file_actions_t *file_actions) {
  if (!file_actions) return EINVAL;
  file_actions->__allocated = 0;
  file_actions->__actions_count = 0;
  file_actions->__actions = NULL;
  return 0;
}

int posix_spawn_file_actions_destroy(posix_spawn_file_actions_t *file_actions) {
  (void)file_actions;
  return 0;
}

int posix_spawn_file_actions_addopen(posix_spawn_file_actions_t *file_actions,
                                     int fd, const char *path, int oflag, mode_t mode) {
  (void)file_actions; (void)fd; (void)path; (void)oflag; (void)mode;
  return 0;
}

int posix_spawn_file_actions_addclose(posix_spawn_file_actions_t *file_actions, int fd) {
  (void)file_actions; (void)fd;
  return 0;
}

int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *file_actions, int fd, int newfd) {
  (void)file_actions; (void)fd; (void)newfd;
  return 0;
}

int posix_spawn(pid_t *pid, const char *path,
                const posix_spawn_file_actions_t *file_actions,
                const posix_spawnattr_t *attrp,
                char *const argv[], char *const envp[]) {
  (void)file_actions;
  (void)attrp;
  pid_t p = vfork();
  if (p == -1) return errno;
  if (p == 0) {
    if (envp)
      execve(path, argv, envp);
    else
      execv(path, argv);
    _exit(127);
  }
  if (pid) *pid = p;
  return 0;
}

int posix_spawnp(pid_t *pid, const char *file,
                 const posix_spawn_file_actions_t *file_actions,
                 const posix_spawnattr_t *attrp,
                 char *const argv[], char *const envp[]) {
  (void)file_actions;
  (void)attrp;
  pid_t p = vfork();
  if (p == -1) return errno;
  if (p == 0) {
    if (envp)
      execvpe(file, argv, envp);
    else
      execvp(file, argv);
    _exit(127);
  }
  if (pid) *pid = p;
  return 0;
}

#endif
