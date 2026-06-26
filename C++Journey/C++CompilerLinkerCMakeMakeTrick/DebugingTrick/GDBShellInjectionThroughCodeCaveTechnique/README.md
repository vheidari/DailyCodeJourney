# Review: Shellcode Injection via the CodeCave Technique

Debugging helps us learn how a process looks in memory. If you read the README.md in the "Debugging Trick" directory, you'll see how GDB and other debugging tools can help us understand a program.

In this post I review how attackers (or security researchers) inject code into a C/C++ program using the "CodeCave" technique, then patch the program via a debugger so it executes x86_64 shellcode.

What does this mean? In short: we locate unused or writable space in a process's memory (a "codecave"), write shellcode there, and modify program flow (for example, by changing a function pointer or a return address) so execution jumps to the injected code. The result is that the target program runs our shellcode.

Below I present a hands-on challenge showing the technique.

## Challenge
I'll write a simple C/C++ console game, then use GDB to locate game logic and modify it by injecting shellcode into a codecave. Finally I'll patch the running program so it transfers execution to the injected shellcode and observe the modified behavior.

## Reference
- https://alon-alush.github.io/injection/codecaves/
- https://hackfa.st/Offensive-Security/Windows-Environment/Establishing-Persistence/Code-Cave-Exploitation/
- https://infosecwriteups.com/code-caving-attacks-how-hackers-stitch-together-code-659f43b103b3
- https://unprotect.it/technique/code-cave/
- https://bista.sites.dmi.unipg.it/didattica/sicurezza-pg/buffer-overrun/hacking-book/0x2a0-writing_shellcode.html
- https://xbz0n.sh/blog/calculator-shellcode-analysis
- https://breakdev.org/x86-shellcode-obfuscation-part-1/
- https://breakdev.org/x86-shellcode-obfuscation-part-2/
- https://github.com/ommadawn46/win-x86-shellcoder
