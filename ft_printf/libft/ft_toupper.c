/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:04:48 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 23:16:08 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief lower case to upper case letter conversion
/// @param c the letter to be converted to upper case
/// @return upper case letter equivalent to `c`, else `c` remains unchanged.
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	printf("src: %c\n", toupper(av[1][0]));
	printf("ft_: %c\n", ft_toupper(av[1][0]));
	return (0);
}
*/
