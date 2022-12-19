/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:21:34 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 23:43:40 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief search for the last occurrence of the character `c` 
/// in the string pointed to, by the argument `s`.
/// @param s the C string.
/// @param c the character to search
/// @return a pointer to the last occurrence of the character in `s`.
/// If no such character is found, NULL is returned.
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == c)
		return ((char *)s + i);
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

	strcpy(src, "This is an example.");
	res_org = strrchr(src, ch);
	res_ft = ft_strrchr(src, ch);
	printf("Origin string is |%s| \n", src);
	printf("src: String after |%c| is - |%s|\n", ch, res_org);
	printf("ft_: String after |%c| is - |%s|\n\n", ch, res_ft);
	return (0);
}
*/
