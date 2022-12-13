/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:21:01 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 23:41:21 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief search for the first occurrence of the character `c` 
/// in the string pointed to by the argument `s`.
/// @param s the C string to be scanned.
/// @param c the character to be searched in `s`.
/// @return a pointer to the first occurrence of the character, 
/// or NULL if no such occurrence
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
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
	res_org = strchr(src, ch);
	res_ft = ft_strchr(src, ch);
	printf("Origin string is |%s| \n", src);
	printf("src: String after |%c| is - |%s|\n", ch, res_org);
	printf("ft_: String after |%c| is - |%s|\n\n", ch, res_ft);
	return (0);
}
*/
