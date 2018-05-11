#include <unistd.h>
#include <stdio.h>
#include "strace.h"
int main() {
  puts("starting strace");
  strace_start();
  for (int i = 0; i < 5; i++)
    sleep(1);
  strace_stop();
  puts("stopped strace");
}
