# How libc starts a C/C++ program and what `__libc_start_main` does

In this section we’ll learn low-level details about libc and how a C/C++ program is started by the operating system. We’ll focus on the role of `__libc_start_main` and how the OS loads and transfers control to an executable.

This part is exciting because it digs into low-level behavior: how the runtime and loader prepare the environment for a C/C++ program, what `__libc_start_main` does, and how it locates and invokes main.

## Challenge

I will write a simple C/C++ program, compile it, and inspect it with GDB to find where `__libc_start_main` begins execution. I will also compile the program with the -s (strip) flag for gcc/g++ to remove symbol tables and debugging sections from the ELF binary (for example, .symtab, .strtab, and .debug_* sections). 

Stripping makes the binary smaller and removes symbol names and debug information, which changes what GDB can show; we’ll use that to observe how `__libc_start_main` locates the program’s main function in memory without symbol information.

Note: The -s flag strips the output file as described above; it instructs the compiler/linker to produce an output without .symtab, .strtab, or .debug_* sections. 

To verify whether a file was stripped, you can run:

```bash
file <executable-name>
```
If the binary was `not stripped`, you might see output like:

./a.out: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=e420002..., for GNU/Linux 3.2.0, not stripped

In that case the file is flagged as “not stripped.”

## Reference links

- __libc_start_main (LSB specification): https://refspecs.linuxbase.org/LSB_3.1.0/LSB-generic/LSB-generic/baselib---libc-start-main-.html  
- musl implementation of `__libc_start_main`: https://git.musl-libc.org/cgit/musl/tree/src/env/__libc_start_main.c#n72
- https://www.gnu.org/software/hurd/glibc/startup.html
