/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:26:12 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 23:08:08 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief test for ASCII character
/// @param c the character to test
/// @return non-zero value if c is an ASCII character, zero otherwise.
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	main(int ac, char **av)
{
	printf("ft: %d\n", ft_isascii(av[1][0]));
	return (0);
}*/
