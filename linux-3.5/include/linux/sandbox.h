#ifndef _LINUX_SANDBOX
#define _LINUX_SANDBOX

#include <asm/syscall.h> /* NR_syscalls */

struct sandbox_class {
  /* comment */
  /* then handler function pointer */
  /* int (*fault_callback) (struct mm_struct *mm, */
  /* 	     struct vm_area_struct *vma, unsigned long address, */
  /* 	     pte_t *pte, pmd_t *pmd, unsigned int flags); */

  /* each task_struct has a sandbox_class member,
     this member is identified by its sandbox id. 
     if a process has (sandbox_id == 0) it means
     the default sandbox (defined in /kernek/sched/sandbox.c) 
  */
  const unsigned int sandbox_id;

  /* the first version will have a simple bitmap
     that disallows certain syscalls from running.

     if the bit disabled_syscalls[SYSCALL_NUM] == 1 then 
     the system call identified by SYSCALL_NUM is disabled.
  */
  DECLARE_BITMAP(disabled_syscalls, NR_syscalls);
};

extern struct sandbox_class *default_sandbox;
extern struct sandbox_class *limited_sandbox;

#endif /* _LINUX_SANDBOX */
