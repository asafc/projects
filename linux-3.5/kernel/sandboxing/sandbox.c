#include <linux/sandbox.h>
#include <linux/export.h>
#include <linux/bitmap.h>

#define getpid_SYSCALL_NUMBER (20)

static unsigned int test_syscall = getpid_SYSCALL_NUMBER;

/* default sandbox class */
static struct sandbox_class default_sandbox_class = {
  .sandbox_id = 0;
};
bitmap_zero(default_sandbox_class->disabled_syscalls, NR_syscalls);

/* this is a simple sandbox for the first version,
   just to see that the limitations work */
static struct sandbox_class limited_sandbox_class = {
  .sandbox_id = 1;
};
bitmap_zero(limited_sandbox_class->disabled_syscalls, NR_syscalls);
set_bit(test_syscall, limited_sandbox_class->disabled_syscalls);

/* exporting our sandboxes to the kernel */
struct sandbox_class *default_sandbox = &default_sandbox_class;
struct sandbox_class *limited_sandbox = &limited_sandbox_class;

EXPORT_SYMBOL(default_sandbox);
EXPORT_SYMBOL(limited_sandbox);
