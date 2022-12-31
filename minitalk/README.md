# get_next_line (gnl)

### Summary

- Keywords: `UNIX` `signal` `process` 

1. Objective
    - coding a small data exchange program using UNIX signals.

2. Instructions
    - **Program name**: `client` and `server` *(both executable file)*
    - **Turn in files**: Makefile, \*.h, \*/\*.h, \*.c, \*/\*.c
    - **Makefile**: NAME, all, clean, fclean, re
    - **External functions**: `write` `malloc`, `free`, `ft_printf` `signal` `sigemptyset` `sigaddset` `sigaction` `kill` `getpid` `pause` `sleep` `usleep` `exit`
    - **Libft authorized**: YES
    - **Limitations**:
        - `Makefile` must not relink.
        - Can have **one global variable per program**, but have to justify their use.
        - The program should not have **memory leaks**.
        - **Handling errors** thoroughly. The program should not quit unexpectedly *(segmentation fault, bus error, double free, and so forth).*

3. Requirements
    - Mandatory: 
        You must create a communication program in the form of a **client** and a **server**.

        - The server must be started first. After its launch, it has to print its `PID` .
        - The client takes two parameters:
            - The server `PID` .
            - The string to send.
        - The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
        - The server has to  display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
            
            <aside>
            💡 1 second for displaying 100 characters is way too much.
            
            </aside>
            
        - The server should be able to receive strings from several clients in a row without needing to restart.
        - The communication between your client and your server has to be done **only** using UNIX signals.
        - Can only use these two signals: `SIGUSR1` AND `SIGUSR2` .
            
            <aside>
            ℹ️ Linux system does NOT queue signals when you already have pending signals of this type.
            
            </aside>

    - Bonus:  
        - The server acknowledge every message received by sending back a signal to the client.
        - Unicode characters support.

### Tester

- [tester]()

    ```bash
    git clone <URL>.git
    ```