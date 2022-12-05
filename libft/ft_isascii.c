/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:26:12 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 22:42:22 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief test for ASCII character
/// @param c the character to test
/// @return non-zero value if c is an ASCII character, zero otherwise.
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
