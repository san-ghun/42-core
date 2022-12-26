/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:22:45 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/16 14:22:12 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief search for the first occurrence of the character 
/// `c` (converted to an unsigned char) in the first `n` bytes 
/// of the string pointed to, by the argument `s`.
/// @param s the pointer to the block of memory where the search in performed.
/// @param c the value to search for, by a byte per byte.
/// @param n the number of bytes to be analyzed.
/// @return a pointer to the matching byte or NULL if no match was found.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (n-- > 0)
	{
		if (tmp[i] == (unsigned char)c)
			return (&tmp[i]);
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
	char	src[100];
	char	ch = 'a';
	char	*res_org;
	char	*res_ft;
	size_t	n;

	n = 10;
	strcpy(src, "This is an example.");
	res_org = memchr(src, ch, n);
	res_ft = ft_memchr(src, ch, n);
	printf("Origin string is |%s| \n", src);
	printf("src: String after |%c| is - |%s|\n", ch, res_org);
	printf("ft_: String after |%c| is - |%s|\n\n", ch, res_ft);
	return (0);
}
*/
