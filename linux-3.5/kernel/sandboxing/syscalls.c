#include <linux/kernel.h>
#include <asm/syscalls.h>

asmlinkage long sys_fork_into_sandbox(unsigned long sandbox_id,
				      struct pt_regs *regs)
{
  return do_fork_into_sandbox(SIGCHLD, regs->sp, regs, 0, NULL, NULL,
			      sandbox_id);
}
