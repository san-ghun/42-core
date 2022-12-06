/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:40:57 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/06 11:03:18 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copy `len` characters from `src` to `dst`, 
/// but for overlapping memory blocks, 
/// memmove() is a safer approach than memcpy().
/// @param dst pointer to destination memory area where content is to be pasted.
/// @param src pointer to the source of data to be copied.
/// @param len the number of bytes to be copied.
/// @return a pointer to the destination, which is `dst`.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;
	char	*s;

	if (dst == src)
		return (dst);
	tmp = dst;
	s = (char *)src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len-- > 0)
		*(tmp + len) = *(s + len);
	return (tmp);
}
