#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

#define SB_FORK (350)

int main(void) 
{
  int pid = 0;
  printf("calling sys_fork_into_sandbox...\n");

  pid = (int) syscall(SB_FORK, 7);
  if(pid == 0) {
    printf("Papa!!\n");
  } else {
    printf("Gingie!! (num: %d)\n", pid);
  }
  return 0;
}
