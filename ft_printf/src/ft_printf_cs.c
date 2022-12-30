/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:17:15 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/29 23:20:03 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_put_s(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		i++;
	}
	return (i);
}
