# pipex

### Summary

- Keywords: `UNIX` `process` `pipe` `folk` `access` `dup2` `execve` `wait` `waitpid`

1. Objective

   - coding a program that handle pipes.

2. Instructions

   - **Program name**: `pipex`
   - **Turn in files**: Makefile, \*.h, \*/\*.h, \*.c, \*/\*.c
   - **Makefile**: NAME, all, clean, fclean, re
   - **Arguments**: file1, cmd1, cmd2, file2
   - **External functions**: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`
   - **Libft authorized**: YES
   - **Requirements**:
     - `Makefile` must not relink.
     - You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).
     - The program should not have **memory leaks**.
     - If you have any doubt, handle the errors like the shell command:
       ```bash
       < file1 cmd1 | cmd2 > file2
       ```

3. Requirements

   - **Mandatory**:

     - Your program will be executed as follows:
       ```bash
       ./pipex file1 cmd1 cmd2 file2
       ```
     - It must take 4 arguments:
       - `file1` and `file2` are **file names**.
       - `cmd1` and `cmd2` are **shell commands** with their parameters.
     - It must behave exactly the same as the shell command below:
       ```bash
       < file1 cmd1 | cmd2 > file2
       ```

   - **Bonus**:
     - Handle multiple pipes.
     - Support « and » when the first parameter is "here_doc".

---

**references)**

- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [My one-month push_swap journey: exploring an easily understandable and efficient algorithm](https://medium.com/@YYBer/my-one-month-push-swap-journey-explore-an-easily-understand-and-efficient-algorithm-11449eb17752)
- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
