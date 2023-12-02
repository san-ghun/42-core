/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:10:17 by minakim           #+#    #+#             */
/*   Updated: 2023/12/02 14:04:30 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "from_ms.h"

/// This was created by borrowing from other code due to a notation issue.
/// @return This function returns 1 if the strings being compared are equal
/// and 0 if they are not.
int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2 && ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}

/// This was created by borrowing from other code due to a notation issue.
/// @return This function returns 1 if the strings being compared are equal
/// and 0 if they are not.
int	ft_strnequ(char const *s1, char const *s2, size_t i)
{
	if (s1 && s2 && ft_strncmp(s1, s2, i) == 0)
		return (1);
	return (0);
}
