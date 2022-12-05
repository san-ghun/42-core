/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:22:45 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 23:06:21 by sanghupa         ###   ########.fr       */
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
