/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:05:23 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 23:16:18 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief upper case to lower case letter conversion
/// @param c the letter to be converted to lower case
/// @return lower case letter equivalent to `c`, else `c` remains unchanged.
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	printf("src: %c\n", tolower(av[1][0]));
	printf("ft_: %c\n", ft_tolower(av[1][0]));
	return (0);
}
*/
