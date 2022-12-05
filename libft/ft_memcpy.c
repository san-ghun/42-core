/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:44:27 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 22:58:06 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copy `n` characters from memory area `src` to memory area `dst`.
/// @param dst pointer to destination memory area where content is to be pasted.
/// @param src pointer to the source of data to be copied.
/// @param n the number of bytes to be copied.
/// @return a pointer to destination, which is `dst`.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp;
	char	*s;

	if (dst == src)
		return (dst);
	i = 0;
	tmp = dst;
	s = (char *)src;
	while (i < n)
	{
		tmp[i] = s[i];
		i++;
	}
	return (tmp);
}
