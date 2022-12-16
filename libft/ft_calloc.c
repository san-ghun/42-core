/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:48:55 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/16 14:41:49 by sanghupa         ###   ########.fr       */
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
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	int		i;
	int		n;
	int		*res_org;
	int		*res_ft;

	printf("Number of elements to be entered:");
	scanf("%d", &n);

	res_org = (int *)calloc(n, sizeof(int));
	res_ft = (int *)ft_calloc(n, sizeof(int));
	printf("Enter %d origin numbers:\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &res_org[i]);
	}
	printf("Enter %d ft numbers:\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &res_ft[i]);
	}

	printf("The numbers entered in origin are: ");
	for (i = 0; i < n; i++) {
		printf("%d ", res_org[i]);
	}
	printf("\n");
	printf("The numbers entered in ft are: ");
	for (i = 0; i < n; i++) {
		printf("%d ", res_ft[i]);
	}
	free(res_org);
	free(res_ft);

	return (0);
}
*/
