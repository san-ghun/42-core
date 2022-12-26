/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:41:00 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 22:41:09 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief alphabetic character test
/// @param c the character to test
/// @return non-zero value if c is an alphabet, zero otherwise.
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	printf("ft: %d\n", ft_isalpha(av[1][0]));
	return (0);
}*/
