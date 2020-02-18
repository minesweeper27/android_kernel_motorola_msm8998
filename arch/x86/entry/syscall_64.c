/* System call table for x86-64. */

#include <linux/linkage.h>
#include <linux/sys.h>
#include <linux/cache.h>
#include <asm/asm-offsets.h>
#include <asm/syscall.h>

<<<<<<< HEAD
#define __SYSCALL_64_QUAL_(sym) sym
#define __SYSCALL_64_QUAL_ptregs(sym) ptregs_##sym

#define __SYSCALL_64(nr, sym, qual) extern asmlinkage long __SYSCALL_64_QUAL_##qual(sym)(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
#include <asm/syscalls_64.h>
#undef __SYSCALL_64

#define __SYSCALL_64(nr, sym, qual) [nr] = __SYSCALL_64_QUAL_##qual(sym),
=======
#define __SYSCALL_COMMON(nr, sym, compat) __SYSCALL_64(nr, sym, compat)

#ifdef CONFIG_X86_X32_ABI
# define __SYSCALL_X32(nr, sym, compat) __SYSCALL_64(nr, sym, compat)
#else
# define __SYSCALL_X32(nr, sym, compat) /* nothing */
#endif

#define __SYSCALL_64(nr, sym, compat) extern asmlinkage long sym(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long) ;
#include <asm/syscalls_64.h>
#undef __SYSCALL_64

#define __SYSCALL_64(nr, sym, compat) [nr] = sym,
>>>>>>> b67a656dc4bbb15e253c12fe55ba80d423c43f22

extern long sys_ni_syscall(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);

asmlinkage const sys_call_ptr_t sys_call_table[__NR_syscall_max+1] = {
	/*
	 * Smells like a compiler bug -- it doesn't work
	 * when the & below is removed.
	 */
	[0 ... __NR_syscall_max] = &sys_ni_syscall,
#include <asm/syscalls_64.h>
};
