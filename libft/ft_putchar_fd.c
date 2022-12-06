/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:39:15 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/06 21:47:53 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief ouput the character `c` to the given file descriptor.
/// @param c the character to ouput.
/// @param fd the file descriptor on which to ouput the character.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
