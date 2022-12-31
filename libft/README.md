# libft

### Summary

- Keywords: `Makefile` `library` `linked list` 

1. Objective
    - coding a C library to create my own library with highly useful standard functions.
    - the functions will be allowed to use in other projects.

2. List of functions
    - Mandatory functions
        - **is_** : [`ft_isdigit`](./ft_isdigit.c) [`ft_isalpha`](./ft_isalpha.c) [`ft_isalnum`](./ft_isalnum.c) [`ft_isascii`](./ft_isascii.c) [`ft_isprint`](./ft_isprint.c) 
        - **to_** : [`ft_toupper`](./ft_toupper.c) [`ft_tolower`](./ft_tolower.c)
        - **string(lib)** : [`ft_strlen`](./ft_strlen.c) [`ft_strlcpy`](./ft_strlcpy.c) [`ft_strlcat`](./ft_strlcat.c) [`ft_strchr`](./ft_strchr.c) [`ft_strrchr`](./ft_strrchr.c) [`ft_strncmp`](./ft_strncmp.c) [`ft_strnstr`](./ft_strnstr.c) [`ft_atoi`](./ft_atoi.c) [`ft_strdup`](./ft_strdup.c) 
        - **string(non-lib)** : [`ft_substr`](./ft_substr.c) [`ft_strjoin`](./ft_strjoin.c) [`ft_strtrim`](./ft_strtrim.c) [`ft_itoa`](./ft_itoa.c) [`ft_strmapi`](./ft_strmapi.c) [`ft_striteri`](./ft_striteri.c) [`ft_split`](./ft_split.c) 
        - **memory** : [`ft_memset`](./ft_memset.c) [`ft_bzero`](./ft_bzero.c) [`ft_memcpy`](./ft_memcpy.c) [`ft_memmove`](./ft_memmove.c) [`ft_memchr`](./ft_memchr.c) [`ft_memcmp`](./ft_memcmp.c) [`ft_calloc`](./ft_calloc.c) 
        - **put_ft** : [`ft_putchar_fd`](./ft_putchar_fd.c) [`ft_putstr_fd`](./ft_putstr_fd.c) [`ft_putendl_fd`](./ft_putendl_fd.c) [`ft_putnbr_fd`](./ft_putnbr_fd.c)

    - Bonus functions
        - **linked_list** : [`ft_lstnew`](./ft_lstnew.c) [`ft_lstadd_front`](./ft_lstadd_front.c) [`ft_lstsize`](./ft_lstsize.c) [`ft_lstlast`](./ft_lstlast.c) [`ft_lstadd_back`](./ft_lstadd_back.c) [`ft_lstdelone`](./ft_lstdelone.c) [`ft_lstclear`](./ft_lstclear.c) [`ft_lstiter`](./ft_lstiter.c) [`ft_lstmap`](./ft_lstmap.c) 

### Tester

- [libft-unit-test](https://github.com/alelievr/libft-unit-test)

    ```bash
    git clone https://github.com/alelievr/libft-unit-test.git
    ```