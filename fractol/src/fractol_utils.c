/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:17:42 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/02 15:40:54 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	double	left;
	double	right;
	char	*c;
	int		sign;
	int		len;

	c = (char *)str;
	sign = 1;
	if (c[0] == '-')
		sign = -1;
	left = (double)ft_atoi(c);
	if (left < 0)
		left *= sign;
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	right = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		right /= 10;
	if (sign == 1)
		return (left + right);
	else
		return (sign * (left + right));
}

// #include <stdio.h>
// #include "libft.h"
// int main()
// {
// 	double d;
// 	d = ft_atof("0");
// 	printf("%f\n", d);
// 	d = ft_atof("0.0");
// 	printf("%f\n", d);
// 	d = ft_atof("0.1");
// 	printf("%f\n", d);
// 	d = ft_atof("0.123");
// 	printf("%f\n", d);
// 	d = ft_atof("123.45");
// 	printf("%f\n", d);
// 	d = ft_atof("12.34");
// 	printf("%f\n", d);
// 	d = ft_atof("-0.34");
// 	printf("%f\n", d);
// 	d = ft_atof("-12.34");
// 	printf("%f\n", d);
// 	return (0);
// }
