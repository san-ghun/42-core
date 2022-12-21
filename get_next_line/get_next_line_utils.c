/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:23:26 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/21 01:25:02 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

/// @brief allocate with malloc() and returns a new string, 
/// which is the result of the concatenation of `s1` and `s2`.
/// @param s1 the prefix string to concatenate
/// @param s2 the suffix string to concatenate
/// @return the new string. NULL if the allocation fails.
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j])
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}
