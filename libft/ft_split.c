/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:04:31 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/06 23:50:16 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	char	*start;
	size_t	i;

	if (!s || !c)
		return (NULL);
	// calculate the length of array, and allocate mem to **tmp.
	// NULL if the allocation fails.
	// iterate through s and check *s == c.
	// if find delimiter, make a chunk of string ending with NULL pointer.
		// insert chunk of string to the array.
	// else iterate and pass through.
	// end the array with NULL pointer.
	return (tmp);
}
