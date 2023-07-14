# push_swap

### Summary

- Keywords: `sorting` `algorithms` `implementation` `data structure`

1. Objective

   - coding a program that sort integer values using 2 stacks and limited number of operations.

2. Instructions

   - **Program name**: `push_swap`
   - **Turn in files**: Makefile, \*.h, \*/\*.h, \*.c, \*/\*.c
   - **Makefile**: NAME, all, clean, fclean, re
   - **Arguments**: `stack_a`: A list of integers
   - **External functions**: `read` `write` `malloc` `free` `exit` `ft_printf`
   - **Libft authorized**: YES
   - **Limitations**:
     - `Makefile` must not relink.
     - Global variables are forbidden.
     - The program should not have **memory leaks**.

3. Requirements

   - **Mandatory**:

     - You have to write a program named push_swap that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
     - The program must display the smallest list of instructions possible to sort the stack `a`, the smallest number being at the top.
     - Instructions must be separated by a ’\n’ and nothing else.
     - The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
     - If no parameters are specified, the program must not display anything and give the prompt back.
     - In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.

   - **Bonus**:
     - Write a program named `checker` that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing

---

**references)**

- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [My one-month push_swap journey: exploring an easily understandable and efficient algorithm](https://medium.com/@YYBer/my-one-month-push-swap-journey-explore-an-easily-understand-and-efficient-algorithm-11449eb17752)
- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
