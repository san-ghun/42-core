/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:48:55 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 22:35:25 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief allocates the requested memory and returns a pointer to it.
///	The difference from malloc is that calloc sets allocated memeory to zero.
/// @param count the number of elements to be allocated.
/// @param size the size of elements.
/// @return a pointer to the allocated memeory, or NULL if the request fails.
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, size * count);
	return (ptr);
}
