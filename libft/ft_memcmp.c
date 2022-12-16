/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:38:01 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/16 14:24:39 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief compare the first `n` bytes of memory area `s1` and memory are `s2`.
/// @param s1 the pointer to a block of memory.
/// @param s2 the pointer to a block of memory.
/// @param n the number of bytes to be compared.
/// @return rv > 0 : s1 > s2, rv < 0 : s1 < s2, rv == 0 : s1 == s2
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	char	str1[50];
	char	str2[50];
	int		n;
	int		res_org;
	int		res_ft;

	strcpy(str1, "This is an example.");
	strcpy(str2, "THIS IS AN EXAMPLE.");
	n = 1;

	res_org = memcmp(str1, str2, n);
	res_ft = ft_memcmp(str1, str2, n);
	printf("str1 is |%s| \n", str1);
	printf("str2 is |%s| \n", str2);
	printf("src: result is - |%d|\n", res_org);
	printf("ft_: result is - |%d|\n\n", res_ft);
	return (0);
}
*/
