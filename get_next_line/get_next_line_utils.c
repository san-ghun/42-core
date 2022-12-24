/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:23:26 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/24 21:27:23 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief compute the length of the string, 
/// but not including the terminating null character
/// @param s the string whose length is to be found.
/// @return the length of the string.
size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/// @brief search for the first occurrence of the character `c` 
/// in the string pointed to by the argument `s`.
/// @param s the C string to be scanned.
/// @param c the character to be searched in `s`.
/// @return a pointer to the first occurrence of the character, 
/// or NULL if no such occurrence
char	*ft_strchr_gnl(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen_gnl((char *)s);
		return (&s[i]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup_gnl(char *s1)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = ft_strlen_gnl(s1);
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/// @brief allocate with malloc() and returns a new string, 
/// which is the result of the concatenation of `s1` and `s2`.
/// @param s1 the prefix string to concatenate
/// @param s2 the suffix string to concatenate
/// @return the new string. NULL if the allocation fails.
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (!s1)
		return (ft_strdup_gnl(s2));
	i = 0;
	j = 0;
	tmp = (char *)malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!tmp)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tmp[i + j] = s2[j];
		j++;
	}
	tmp[i + j] = '\0';
	free(s1);
	return (tmp);
}
