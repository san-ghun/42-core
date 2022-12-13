/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:05:13 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 23:04:38 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copy the character `c` to the first `n` characters of 
/// the string pointed to, by the argument `str`.
/// @param b a pointer to the block of memory to fill.
/// @param c the value to be set.
/// @param len the number of bytes to be set to the value.
/// @return a pointer to the memory area `b`.
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}
