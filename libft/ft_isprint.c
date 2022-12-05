/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:41:18 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/05 22:44:57 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief printing character test (space character inclusive)
/// @param c the character to test
/// @return non-zero value if c is a printable, zero otherwise.
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
