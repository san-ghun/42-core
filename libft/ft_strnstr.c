/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:44:43 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 23:30:38 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief finds the first occurrence of the substring `needle` 
/// in the string `haystack`, where not more than `len`. 
/// The terminating '\0' characters are not compared.
/// @param haystack the main C string to be scanned.
/// @param needle the small string to be searched with-in haystack.
/// @param len the maximum number of characters to search.
/// @return a pointer to the first occurrence of `needle` 
/// in the string `haystack`. If `needle` is empty, `haystack` is returned;
/// if `needle` is not occurs in `haystack`, NULL is returned.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_hs;
	size_t	len_nd;
	size_t	len_tmp;
	size_t	i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	len_hs = ft_strlen(haystack);
	len_nd = ft_strlen(needle);
	if (len_hs < len_nd || len < len_nd)
		return (0);
	if (len_hs > len)
		len_tmp = len;
	else
		len_tmp = len_hs;
	i = 0;
	while (i + len_nd <= len_tmp)
	{
		if (ft_strncmp(haystack + i, needle, len_nd) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
