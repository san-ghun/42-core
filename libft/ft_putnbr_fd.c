/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:07:33 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/16 14:55:28 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief output the integer `n` to the given file descriptor
/// @param n the integer to output.
/// @param fd the file descriptor on which to write.
void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
		write(fd, INT_MIN_STR, 11);
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	int	n;

	n = 123456799;
	ft_putnbr_fd(n, 1);
	return (0);
}
*/
