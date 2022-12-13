/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:52:47 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 23:21:31 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copy up to `dstsize` characters from the string pointed to, 
/// by src to dst. In a case where the length of src is less than 
/// that of dstsize, the remainder of dst will be padded with null bytes.
/// @param dst pointer to the dest array where the content is to be pasted.
/// @param src the string to be copied.
/// @param dstsize The number of characters to be copied from source.
/// @return the pointer to the pasted string.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (len_src);
	while ((src[i] != '\0') && (i + 1 < dstsize))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	while (src[i] != 0)
		i++;
	return (i);
}
