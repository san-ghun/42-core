# ft_printf

### Summary

- Keywords: `variadic function` `ctype`

1. Objective
    - recoding the `printf()` in C.
    - learn about `variadic function` in C.
    - practice to code a well-structured and extensible code.
    - the functions will be allowed to use in other projects.

2. List of functions
    - Mandatory
        - **description** : Write a library that contains `ft_printf()`, a function that will mimic the original `printf()`
        - **external functions** : `malloc` `free` `write` `va_start` `va_arg` `va_copy` `va_end`
        - **prototype** : 
            ```C
            int ft_printf(const char *, ...);
            ```
        - **conversion** : `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%` 

    - Bonus
        - **conversion** : `%n` `%f` `%g` `%e`
        - **flag** : `-` `0` `.` `*` `#` ` ` `+`

### Tester

- [printfTester](https://github.com/Tripouille/printfTester)

    ```bash
    git clone https://github.com/Tripouille/printfTester.git
    ```