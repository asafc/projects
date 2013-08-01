#ifndef _LINUX_SANDBOX
#define _LINUX_SANDBOX


#define NUM_OF_SYSCALLS 350

#include <linux/kernel.h>
#include <linux/bitops.h>
#include <linux/types.h>

struct sandbox_class {
  /* 
     this bitmap disallows certain syscalls from running.
     if the bit syscalls[SYSCALL_NUM] == 1 then 
     the system call identified by SYSCALL_NUM is disabled.
  */
  DECLARE_BITMAP(syscalls, NUM_OF_SYSCALLS);
};

extern struct sandbox_class * sandbox_list;
extern void init_sandbox_list(void);

#endif /* _LINUX_SANDBOX */
