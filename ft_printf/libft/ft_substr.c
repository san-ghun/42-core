/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:42:15 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/23 16:33:48 by sanghupa         ###   ########.fr       */
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
	size_t	strlen;
	char	*tmp;

	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	if (strlen < len)
		len = strlen;
	i = 0;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	while (len-- && s[start])
		tmp[i++] = s[start++];
	tmp[i] = '\0';
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
