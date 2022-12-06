/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:57:26 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/06 21:36:26 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief apply the function `f` on each character of the string 
/// passed as argument, passing its index as first argument. 
/// Each character is passed by address to `f` to be modified if necessary.
/// @param s the string on which to iterate.
/// @param f the function to apply to each character.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = '\0';
	return ;
}
