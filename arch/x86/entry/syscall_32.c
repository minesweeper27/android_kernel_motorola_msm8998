/* System call table for i386. */

#include <linux/linkage.h>
#include <linux/sys.h>
#include <linux/cache.h>
#include <asm/asm-offsets.h>
#include <asm/syscall.h>

<<<<<<< HEAD
#define __SYSCALL_I386(nr, sym, qual) extern asmlinkage long sym(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long) ;
#include <asm/syscalls_32.h>
#undef __SYSCALL_I386

#define __SYSCALL_I386(nr, sym, qual) [nr] = sym,
=======
#ifdef CONFIG_IA32_EMULATION
#define SYM(sym, compat) compat
#else
#define SYM(sym, compat) sym
#endif

#define __SYSCALL_I386(nr, sym, compat) extern asmlinkage long SYM(sym, compat)(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long) ;
#include <asm/syscalls_32.h>
#undef __SYSCALL_I386

#define __SYSCALL_I386(nr, sym, compat) [nr] = SYM(sym, compat),
>>>>>>> b67a656dc4bbb15e253c12fe55ba80d423c43f22

extern asmlinkage long sys_ni_syscall(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);

__visible const sys_call_ptr_t ia32_sys_call_table[__NR_syscall_compat_max+1] = {
	/*
	 * Smells like a compiler bug -- it doesn't work
	 * when the & below is removed.
	 */
	[0 ... __NR_syscall_compat_max] = &sys_ni_syscall,
#include <asm/syscalls_32.h>
};
