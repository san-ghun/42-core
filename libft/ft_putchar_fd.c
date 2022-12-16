/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:39:15 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/16 14:45:06 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief ouput the character `c` to the given file descriptor.
/// @param c the character to ouput.
/// @param fd the file descriptor on which to ouput the character.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	char	ch;

	printf("origin:\n");
	for (ch = 'A'; ch <= 'z'; ch++) {
		putchar(ch);
	}
	printf("\n");
	printf("ft:\n");
	for (ch = 'A'; ch <= 'z'; ch++) {
		ft_putchar_fd(ch, 1);
	}
	return (0);
}
*/
