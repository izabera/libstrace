#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include "strace.h"

int main() {
  puts("starting strace");
  strace_start("strout");
  for (int i = 0; i < 50; i++) {
    usleep(100 * 1000);
  }
  strace_stop();
  puts("stopped strace");

  puts("restarting strace");
  strace_start("strout-crash");
  assert(!"and now let's crash");
}
