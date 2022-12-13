/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:52:47 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 23:28:19 by sanghupa         ###   ########.fr       */
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
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	char	src[100];
	char	dst_org[100];
	char	dst_ft[100];

	strcpy(src, "This is an example.");
	strlcpy(dst_org, src, 15);
	ft_strlcpy(dst_ft, src, 15);
	printf("Copy 10 of |%s| is: \n", src);
	printf("src: %s\n", dst_org);
	printf("ft_: %s\n", dst_ft);
	return (0);
}
*/
