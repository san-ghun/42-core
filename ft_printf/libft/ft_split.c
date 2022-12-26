/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:04:31 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/16 16:22:36 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_size(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			len++;
			while (*s && *s != c)
				s++;
		}
		if (*s)
			s++;
	}
	return (len);
}

char	**ft_split_process(char const *s, char c, char **tmp, size_t i)
{
	char	*start;

	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			tmp[i] = (char *)malloc(sizeof(char) * (s - start + 1));
			if (!tmp[i])
				return (NULL);
			ft_strlcpy(tmp[i++], start, s - start + 1);
		}
		if (*s)
			s++;
	}
	tmp[i] = NULL;
	return (tmp);
}

/// @brief allocate with malloc() and returns an array of strings 
/// obtained by splitting `s` using the character `c` as a delimiter. 
/// The array must end with a NULL pointer.
/// @param s the string to be split.
/// @param c the delimiter character.
/// @return the array of new strings resulting from the split. 
/// NULL if the allocation fails.
char	**ft_split(char const *s, char c)
{
	char	**tmp;
	size_t	i;

	if (!s)
		return (NULL);
	tmp = (char **)malloc(sizeof(char *) * (ft_split_size(s, c) + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	tmp = ft_split_process(s, c, tmp, i);
	return (tmp);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	int		i;
	int		n;
	char	*input = "     split      this    for   me  !     ";
	char	**expected = ((char *[6]){"split", "this", "for", "me", "!", NULL});
	char	**result;

	result = ft_split(input, ' ');

	for (; *expected; expected++, result++) {
		printf("exp: %s \n", *expected);
		printf("res: %s \n\n", *result);
	}

	return (0);
}
*/
