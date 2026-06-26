## How to find who called a function using GDB 

This guide shows how to perform reverse-call (caller) analysis in a C/C++ program with GDB. We'll inspect stack frames and use commands such as `break`, `bt`, `catch syscall`, `frame <n>`, `up`, `down`, and `display/x <register>` to determine which function called a target function (here named `whocallme`). This technique is useful when you need to discover how a library or executable invokes a particular function — for example when you only have a stripped binary and don't access to source code. In the next section we will go through a simple example and explain that technique.

## Challenge
We have a C/C++ program (main.cpp) with three functions: `main`, `keyGenerator`, and `whocallme`. `main` calls `keyGenerator`; `keyGenerator` calls `whocallme`. `keyGenerator` generates and sends an encrypted key to `whocallme` based on input; `whocallme` prints the key using `std::cout`.

The problem: if we don't have source code, how can we understand how the executable works? How is the encryption key generated? Which functions call each other to produce the printed key? How can we find the function that prints the key and the function that generates it, especially if the executable is stripped?

