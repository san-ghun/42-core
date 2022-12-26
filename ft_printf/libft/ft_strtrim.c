/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:36:20 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/16 15:30:21 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief allocate with malloc() and returns a copy of `s1` 
/// with the characters specified in `set` removed from 
/// the beginning and the end of the string.
/// @param s1 the string to be trimmed.
/// @param set the reference set of characters to trim.
/// @return the trimmed string. NULL if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*tmp;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && start < end)
		end--;
	tmp = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, &s1[start], end - start + 1);
	return (tmp);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	printf("%s\n", ft_strtrim("abqbc", "abc"));
	printf("%s\n", ft_strtrim("xavocadoyz", "xyz"));
	printf("%s\n", ft_strtrim("    space    ", " "));
	return (0);
}
*/
