/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:52:26 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 22:43:40 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief decimal-digit character test
/// @param c the character to test
/// @return non-zero value if c is a digit, zero otherwise.
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	printf("ft: %d\n", ft_isdigit(av[1][0]));
	return (0);
}*/
