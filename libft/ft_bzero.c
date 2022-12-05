/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:24:14 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 22:29:46 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief write zeros to a byte string
/// @param s a byte string
/// @param n size of zeros to write
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
int	main(void)
{
	char buffer[100] = "Hello, Greetings! Testing the bzero Function";
	printf("Display of Buffer String BEFORE bzero Function: %s\n", buffer);
	//bzero(buffer, 100);
	ft_bzero(buffer, 100);
	// ft_bzero(buffer, 0);
	printf("Display of Buffer String AFTER bzero Function: %s\n", buffer);
	return (0);
}
*/
