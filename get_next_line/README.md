# get_next_line (gnl)

### Summary

- Keywords: `static variable` `file descriptor`

1. Objective
    - coding a function that returns a line ending with a newline, and read from a file descriptor.
    - the functions will be allowed to use in other projects.

2. List of functions
    - Mandatory: [`get_next_line.h`](./get_next_line.h) [`get_next_line.c`](./get_next_line.c) [`get_next_line_utils.c`](./get_next_line_utils.c) 
        - **description** : Write a function that returns a line read from a file descriptor
        - **external functions** : `read` `malloc` `free` 
        - **limitation** : `libft.a` is not available, up to 5 functions can be added in `get_next_line_utils.c`
        - **compile call example** : 
            ```bash
            cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
            ```
        - **forbidden** : 
            - not allowed to use `libft` in the project.
            - `lseek()` is forbidden.
            - Global variables are forbidden.

    - Bonus: [`get_next_line_bonus.h`](./get_next_line_bonus.h) [`get_next_line_bonus.c`](./get_next_line_bonus.c) [`get_next_line_utils_bonus.c`](./get_next_line_utils_bonus.c) 
        - **requirements** : 
            - Develop `get_next_line()` using only one static variable.
            - Develop `get_next_line()` to be able to manage multiple file descriptors without losing the reading thread of each file descriptor.

### Tester

- [gnlTester](https://github.com/Tripouille/gnlTester)

    ```bash
    git clone https://github.com/Tripouille/gnlTester.git
    ```