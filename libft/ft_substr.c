/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:42:15 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/16 15:23:04 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief allocate with malloc() and returns a substring from `s`.
/// The substring begins at index `start` and is of maximum size `len`.
/// @param s The string from which to create the substring.
/// @param start The start index of the substring in the string ’s’.
/// @param len The maximum length of the substring.
/// @return The substring. NULL if the allocation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	tmp[len] = '\0';
	while (len--)
		tmp[i++] = s[start++];
	return (tmp);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Doesn't work in my Mac, rather try on Linux.
int	main(int ac, char **av)
{
	char	*s;
	char	*tmp;

	strcpy(s, "This is an example.");
	tmp = ft_substr(s, av[1][0], av[2][0]);
	printf("%s\n", tmp);

	free(tmp);
	return (0);
}
*/
