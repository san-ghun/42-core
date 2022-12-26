/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:40:57 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/16 14:18:40 by sanghupa         ###   ########.fr       */
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
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	const char	src[50] = "This is an example.";
	char		dst_org[50];
	char		dst_ft[50];
	size_t		n;

	strcpy(dst_org, "Just some test.");
	strcpy(dst_ft, "Just some test.");
	// n = strlen(src) + 1;
	n = 4;

	printf("src is : %s\n", src);

	puts(dst_org);
	memmove(dst_org, src, n);
	puts(dst_org);

	puts(dst_ft);
	ft_memmove(dst_ft, src, n);
	puts(dst_ft);

	return(0);
}
*/
