/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 */

#ifdef __ANDROID__

#include <libcompat/progname.h>
#include <stdlib.h>
#include <string.h>

char *program_invocation_name = "program";
char *program_invocation_short_name = "program";

__attribute__((constructor))
static void __init_progname(int argc, char **argv, char **envp) {
  (void)argc;
  (void)envp;
  if (argv && argv[0]) {
    program_invocation_name = argv[0];
    char *slash = strrchr(argv[0], '/');
    program_invocation_short_name = slash ? slash + 1 : argv[0];
  } else {
    const char *p = getprogname();
    if (p && *p) {
      program_invocation_name = (char *)p;
      program_invocation_short_name = (char *)p;
    }
  }
}

#endif
