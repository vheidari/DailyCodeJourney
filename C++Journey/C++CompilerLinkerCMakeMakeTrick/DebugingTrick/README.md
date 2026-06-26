# Here I would like to write some usefull information about debugging techniqe and tools 
Some times we saw some people talk about debugging and they say that they don't need a debugger, and they just use `printf` to debug their code, and they are right, but here I would like to talk about some of the advantages of using a debugger I would like to review `gdb`and some usefull tools that allow us to debug our code and learn how these tools can help us to find and fix bugs in our code more efficiently.

these tools help us to learn how our machine and `C/C++` program work.

we will go to learn about `gdb`, `ld`, `strace`, `ltrace`, `valgrind`, `strings`, `objdump`, `dd`, `hexdump`, `xxd`, `file`, `readelf`, `ldd`, `info` , `dd`, `nm` tools. I would like implement so simple secnario and review it that how we can use each one to get information about our binary file.

we will go to learn how a `ELF` file is structured and how to use `readelf` to analyze the structure of an `ELF` file and how to use `objdump` to disassemble an `ELF` file and how to use `strings` to find strings in an `ELF` file and how to use `file` to determine the type of a file and how to use `hexdump` and `xxd` to view the contents of a file in hexadecimal format and how to use `dd` to create a copy of a file and how to use `valgrind` to find memory leaks in our code and how to use `strace` and `ltrace` to trace system calls and library calls made by our code and `ldd` that help us to check dependencies, `nm` is responsiable to check lists of the symbols from an object file.

I like all these stuff and other low level that give us a overview about whole system. belong to these tools and examples I love to review many  

we will go to learn how to use `gdb` to debug our code and how to set breakpoints, how to step through our code, how to inspect variables and how to use `gdb` to find and fix bugs in our code more efficiently.

another thing that I would like to talk about is finding offset between runtime memory address and address that file stored in disk, and how to use `gdb` to find the offset between runtime memory address and address that file stored in disk and how to use this offset to find the address of a function or a variable in our code and how to use this address to find and fix bugs in our code more efficiently.

we will go to learn how we can patch our code using `gdb` and how to use `gdb` to modify the contents of a variable or a function in our code and how to use this technique to find and fix bugs in our code more efficiently.

we will go to learn about `CPU` registers and how to use `gdb` to view the contents of `CPU` registers and how to use this information to find and fix bugs in our code more efficiently.


# Quick CPU Registers review
- `RIP`: Instruction Pointer, holds the address of the next instruction to be executed.
- `RSP`: Stack Pointer, points to the top of the stack.
- `RBP`: Base Pointer, used to reference local variables and function parameters on the stack.
- `RAX`, `RBX`, `RCX`, `RDX`, `RSI`, `RDI`, `R8`-`R15`: General-purpose registers used for various operations and function arguments.
- `EFLAGS`: Flags register, contains status flags that indicate the state of the processor and control certain operations.
- `CS`, `DS`, `ES`, `FS`, `GS`, `SS`: Segment registers, used to hold segment selectors for memory access.
- `RIP`, `RSP`, and `RBP` are particularly important for understanding the flow of execution and the structure of the stack during debugging. 

Understanding these registers is crucial for effectively using `gdb` to analyze and debug your code, as they provide insights into the program's execution state and help you identify issues related to control flow, memory access, and function calls.

here I would like example each register and how they will appear in debubging session.

## `RIP` (Instruction Pointer):
- Example: When you set a breakpoint at the `main` function and run the program, the `RIP` register will point to the address of the `main` function when the breakpoint is hit. This allows you to see the next instruction that will be executed when you step through 


## GDB command first look
- `gdb <executable>`: This command is used to start `gdb` and load the specified executable file for debugging.
- `gdb -q <executable>`: This command starts `gdb` in quiet mode, which suppresses the introductory messages and prompts, providing a cleaner interface for debugging.
- `gdb -p <pid>`: This command attaches `gdb` to a running process with the specified process ID (PID), allowing you to debug the process in real-time.
- `gdb -c <corefile>`: This command loads a core dump file for analysis, allowing you to investigate the state of a program at the time it crashed.
- `gdb -ex <command> <executable>`: This command allows you to execute a specific `gdb` command immediately after starting `gdb` with the specified executable. For example, `gdb -ex "break main" -ex "run" <executable>` will set a breakpoint at the `main` function and then start the execution of the program.
- `gdb -ex <command> -p <pid>`: This command allows you to execute a specific `gdb` command immediately after attaching to a running process. For example, `gdb -ex "break main" -ex "continue" -p <pid>` will set a breakpoint at the `main` function and then continue the execution of the process.
- `gdb -ex <command> -c <corefile>`: This command allows you to execute a specific `gdb` command immediately after loading a core dump file. For example, `gdb -ex "bt" -c <corefile>` will display the backtrace of the program at the time it crashed.
- `gdb -ex <command> -ex <command> <executable>`: This command allows you to execute multiple `gdb` commands immediately after starting `gdb` with the specified executable. For example, `gdb -ex "break main" -ex "run" <executable>` will set a breakpoint at the `main` function and then start the execution of the program.
- `gdb -ex <command> -ex <command> -p <pid>`: This command allows you to execute multiple `gdb` commands immediately after attaching to a running process. For example, `gdb -ex "break main" -ex "continue" -p <pid>` will set a breakpoint at the `main` function and then continue the execution of the process.
- `layout <layout>`: This command is used to change the layout of the `gdb` interface. The available layouts include `tui`, `src`, `asm`, `regs`, and `split`.
    - `layout src`: This layout displays the source code of the program being debugged.
    - `layout asm`: This layout displays the assembly code of the program being debugged.
    - `layout regs`: This layout displays the contents of the CPU registers.
    - `layout split`: This layout splits the interface into multiple panes, allowing you to view different aspects of the program simultaneously.

- `run [arguments]`: This command is used to start the execution of the program being debugged. You can provide any necessary arguments for the program.
    -`run password123`: Start the execution of the program with the argument `password123`.
- `break <location>`: This command is used to set a breakpoint at a specific location in the code. The location can be specified as a function name, a line number, or an address.
    - `break main`: Set a breakpoint at the beginning of the `main` function.
    - `break 42`: Set a breakpoint at line 42 of the current source file
    - `break *0x400123`: Set a breakpoint at the specified memory address.
    - `break <function>:<line>`: Set a breakpoint at a specific line in a specific source file.
      - ex -> `break main:147`: Set a breakpoint at line 147 of the `main` function.
    - ``break <file>:<line>` : Set a breakpoint at a specific line in a specific source file.
      - ex -> `break main.c:147`: Set a breakpoint at line 147 of the `main.c` source file.
- `info breakpoints`: This command is used to display a list of all the breakpoints that have been set in the current debugging session, along with their locations and statuses.
- `info registers`: This command is used to display the current values of all the CPU registers. This information can be useful for understanding the state of the program at a specific point in time and for diagnosing issues related to control flow, memory access, and function calls.

- `delete <breakpoint number>`: This command is used to delete a specific breakpoint by
    its number. You can find the breakpoint number by using the `info breakpoints` command.
        - `delete 1`: Delete the breakpoint with the number 1.
- `disable <breakpoint number>`: This command is used to disable a specific breakpoint by its number. The breakpoint will remain in place but will not be active until it is re-enabled.
    - `disable 1`: Disable the breakpoint with the number 1.
- `enable <breakpoint number>`: This command is used to enable a specific breakpoint by its number. The breakpoint will become active and will cause the program to stop when it is hit.
    - `enable 1`: Enable the breakpoint with the number 1.
- `clear <location>`: This command is used to clear a breakpoint at a specific location

- `x/<format> <address>`: This command is used to examine the memory at a specific address. The `<format>` specifies how the memory should be displayed (e.g., `x` for hexadecimal, `d` for decimal, `s` for string, etc.).
    - `x/x 0x400123`: Display the memory at address `0x400123` in hexadecimal format.
    - `x/d 0x400123`: Display the memory at address `0x400123` in decimal format.
    - `x/s 0x400123`: Display the memory at address `0x400123` as a string.
- `p <expression>`: This command is used to evaluate and print the value of an expression. The expression can be a variable, a register, or any valid C expression.
    - `p variable_name`: Print the value of the variable `variable_name`.
    - `p $rax`: Print the value of the `RAX` register.
    - `p variable_name + 10`: Print the result of adding 10 to the value of `variable_name`.
- `bt`: This command is used to display the backtrace of the current execution stack. The backtrace shows the sequence of function calls that led to the current point in the program, along with the arguments passed to each function. This information can be useful for understanding the flow of execution and for diagnosing issues related to function calls and control flow.
- `continue`: This command is used to continue the execution of the program after it has been stopped at a breakpoint or after a step command. The program will continue running until it hits another breakpoint, encounters an error, or finishes execution.
- `step`: This command is used to execute the next line of code, stepping into any function calls. If the next line of code contains a function call, `gdb` will step into that function and allow you to debug it line by line.
- `next`: This command is used to execute the next line of code, stepping over any function calls. If the next line of code contains a function call, `gdb` will execute the entire function and then stop at the next line of code after the function call.
- `finish`: This command is used to continue execution until the current function returns. This is useful when you have stepped into a function and want to quickly return to the caller without stepping through the entire function.
- `quit`: This command is used to exit the `gdb` debugging session. You will be prompted to confirm that you want to quit, and any unsaved changes to the debugging session will be lost. Use this command when you are finished debugging and want to exit `gdb`.  

- `set <option> <value>`: This command is used to set various options in `gdb`. For example, you can use `set pagination off` to disable pagination of output, or `set print pretty on` to enable pretty-printing of complex data structures.
    - `set pagination off`: Disable pagination of output, allowing all output to be displayed at once.
    - `set print pretty on`: Enable pretty-printing of complex data structures, making them easier to read and understand.

- `set register <register> = <value>`: This command is used to set the value of a specific CPU register. This can be useful for modifying the state of the program during debugging or for testing how changes to register values affect the program's behavior.
    - `set register rax = 0x1234`: Set the value of the `RAX` register to `0x1234`.
    - `set register rsp = 0x7fffffffe000`: Set the value of the `RSP` register to `0x7fffffffe000`.
        - `set $rax = 0x1234`: Another way to set the value of the `RAX` register to `0x1234`.
        - `set $rsp = 0x7fffffffe000`: Another way to set the value of the `RSP` register to `0x7fffffffe000`.
- `set breakpoint pending on`: This command is used to allow `gdb` to set breakpoints in shared libraries that have not yet been loaded. When this option is enabled, `gdb` will set breakpoints in the shared library as soon as it is loaded, allowing you to debug code in the shared library even if it is not loaded at the time you set the breakpoint.
    - `set breakpoint pending on`: Enable the option to allow `gdb` to set breakpoints in shared libraries that have not yet been loaded.

- `set {unsigned char[2]}<address> = {0x90, 0x90}`: This command is used to set the value of a specific memory location to a sequence of bytes. In this example, it sets the memory at the specified address to two `NOP` instructions (0x90 in x86 assembly), which can be useful for patching code during debugging.
    - `set {unsigned char[2]}0x400123 = {0x90, 0x90}`: Set the memory at address `0x400123` to two `NOP` instructions.

- `set {unsigned char[2]}0x555555555211= {0xEB, main+128}`: This command is used to set the memory at address `0x555555555211` to a jump instruction (`0xEB`) that jumps to the address of `main` plus an offset of 128 bytes. This can be useful for redirecting the flow of execution during debugging.
    - `set {unsigned char[2]}0x555555555211= {0xEB, main+128}`: Set the memory at address `0x555555555211` to a jump instruction that jumps to the address of `main` plus an offset of 128 bytes.


`set disassembly-flavor att
set disassembly-flavor intel
show disassembly-flavor`

https://visualgdb.com/gdbreference/commands/set_disassembly-flavor


- `disassemble <function>`: This command is used to disassemble the machine code of a specific function, showing the assembly instructions that correspond to the function's code. This can be useful for understanding how the function works at a low level and for diagnosing issues related to control flow and instruction execution.
    - `disassemble main`: Disassemble the machine code of the `main` function, showing its assembly instructions.


- `dump binary memory <filename> <start address> <end address>`: This command is used to dump a specific range of memory to a binary file. This can be useful for analyzing the contents of memory or for creating a snapshot of the program's state at a specific point in time.
    - `dump binary memory memory_dump.bin 0x400000 0x401000`: Dump the memory from address `0x400000` to `0x401000` into a binary file named `memory_dump.bin`.