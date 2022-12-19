/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:40:21 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 23:07:41 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief alphanumeric character test
/// @param c the character to test
/// @return non-zero value if c is a digit or a letter, zero otherwise.
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	main(int ac, char **av)
{
	printf("ft: %d\n", ft_isalnum(av[1][0]));
	return (0);
}*/
