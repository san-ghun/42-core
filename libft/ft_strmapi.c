/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:31:45 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/16 15:39:53 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief apply the function `f` to each character of the string `s`, 
/// and passing its index as first argument to create a new string 
/// with malloc() resulting from successive applicatioins of `f`.
/// @param s the string on which to iterate.
/// @param f the function to apply to each character.
/// @return the string created from the successive application of `f`. 
/// Returns NULL if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char	f(unsigned int i, char c)
{
	char	ch;

	ch = c + 1;
	return (ch);
}
int	main(int ac, char **av)
{
	char	*str1;
	char	*tmp;

	tmp = ft_strmapi(&av[1][0], *f);
	printf("%s\n", tmp);

	free(tmp);
	return (0);
}
*/
