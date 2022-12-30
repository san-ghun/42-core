/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:17:41 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/30 02:17:43 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_uhexlen(unsigned long long nbr)
{
	int	i;

	i = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int	ft_put_p(unsigned long long p)
{
	int		len;
	char	*base;

	len = 0;
	write(1, "0x", 2);
	len += 2;
	base = "0123456789abcdef";
	if (p > 15)
	{
		ft_put_hex(p / 16, 0);
		ft_put_hex(p % 16, 0);
	}
	else
		write(1, &base[p], 1);
	len += ft_get_uhexlen(p);
	return (len);
}
