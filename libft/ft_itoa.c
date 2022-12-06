/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:22:22 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/06 14:46:43 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n, int len)
{
	while (n /= 10)
		len++;
	return (len);
}

static char	*ft_itoa_tmp(char *tmp, unsigned int nb, int len)
{
	tmp[--len] = nb % 10 + '0';
	while (nb /= 10)
		tmp[--len] = nb % 10 + '0';
	return (tmp);
}

/// @brief allocate with malloc() and returns a string representing 
/// the integer received as a argument. Negative numbers must be handled.
/// @param n the integer to convert.
/// @return the string representing the integer. NULL if the allocation fails.
char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				sign;
	int				len;
	char			*tmp;

	sign = 0;
	len = 1;
	if (n < 0)
	{
		sign = 1;
		len++;
		nb = (unsigned int)(-n);
		n *= -1;
	}
	else
		nb = (unsigned int)n;
	len = ft_itoa_len(n, len);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	if (sign)
		tmp[0] = '-';
	tmp[len] = '\0';
	return (ft_itoa_tmp(tmp, nb, len));
}
