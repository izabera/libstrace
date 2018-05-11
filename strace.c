#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "strace.h"

static int strace_pid;

int strace_start(void) {
  char mypid[10];
  char *args[] = { "strace", "-p", mypid, 0 };
  sprintf(mypid, "%d", getpid());
  return strace_start_with_args(args);
}

int strace_start_with_args(char * const *args) {
  if (strace_pid > 0) return -1;

  char mypid[10];
  sprintf(mypid, "%d", getpid());
  strace_pid = fork();

  if (!strace_pid)
    return execvp("strace", args);
  return 0;
}

int strace_stop(void) {
  if (strace_pid <= 0) return strace_pid;

  if (kill(strace_pid, SIGTERM) < 0)
    return -1;

  int status;
  return waitpid(strace_pid, &status, 0) < 0 ? -1 : 0;
}
