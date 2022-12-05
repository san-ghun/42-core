/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:53:05 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 23:17:58 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief append the string pointed to by `src` to the end of the string 
/// pointed to by `dst` up to `dstsize` characters long.
/// @param dst pointer to the destination array, which should contain 
/// a C string, and should be large enough to contain the concatenated 
/// resulting string which includes the additional null-character.
/// @param src the string to be appended.
/// @param dstsize the maximum number of characters to be appended.
/// @return a pointer to the resulting string dst.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	while ((src[i] != 0) && (dstsize > i + len_dst + 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_dst + len_src);
}
