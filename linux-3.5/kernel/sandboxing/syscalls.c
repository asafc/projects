#include <asm/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/compiler.h>

#define BLOCK_SYSCALL 1
#define SYSCALL_OK 0

asmlinkage long sys_fork_into_sandbox(unsigned long sandbox_id,
				      struct pt_regs *regs)
{
  return do_fork_into_sandbox(SIGCHLD, regs->sp, regs, 0, NULL, NULL,
			      sandbox_id);
}

asmlinkage int sandbox_block_syscall(int syscall_num) {
  if (unlikely(test_bit(syscall_num, current_sandbox.syscalls))) {
    return BLOCK_SYSCALL;
  }

  return SYSCALL_OK;
}


