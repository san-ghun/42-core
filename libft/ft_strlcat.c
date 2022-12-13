/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:53:05 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 23:33:46 by sanghupa         ###   ########.fr       */
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
	strcpy(dst_org, "To origin.");
	strcpy(dst_ft, "To ft----.");
	strlcat(dst_org, src, 15);
	ft_strlcat(dst_ft, src, 15);
	printf("Cat 15 of |%s| is: \n", src);
	printf("src: %s\n", dst_org);
	printf("ft_: %s\n", dst_ft);
	return (0);
}
*/
