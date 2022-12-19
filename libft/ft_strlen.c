/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:46:47 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 23:22:54 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief compute the length of the string, 
/// but not including the terminating null character
/// @param s the string whose length is to be found.
/// @return the length of the string.
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (i);
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	char	str[50];
	int		len_src;
	int		len_ft;

	strcpy(str, "This is an example.");
	len_src = (int)strlen(str);
	len_ft = (int)ft_strlen(str);
	printf("Length of |%s| is: \n", str);
	printf("src: %d\n", len_src);
	printf("ft_: %d\n", len_ft);
	return (0);
}
*/
