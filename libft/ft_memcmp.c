/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:38:01 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 22:54:34 by sanghupa         ###   ########.fr       */
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
