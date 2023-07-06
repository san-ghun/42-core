/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_val_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:15:18 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/06 17:08:27 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_str_isdigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			if (*str != '-')
				return (1);
		str++;
	}
	return (0);
}

int	ft_str_isinteger(char *str)
{
	if (ft_atol(str) > (double)INT_MAX)
		return (1);
	if (ft_atol(str) < (double)INT_MIN)
		return (1);
	return (0);
}

int	ft_str_isduplicate(char *arg[])
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (arg[i + 1] != NULL)
	{
		j = i + 1;
		while (arg[j] != NULL)
		{
			if (ft_strlen(arg[i]) < ft_strlen(arg[j]))
				len = ft_strlen(arg[j]);
			else
				len = ft_strlen(arg[i]);
			if (ft_strncmp(arg[i], arg[j], len) == 0)
			{
				// ft_printf("s%d %s, s%d %s\n", i, arg[i], j, arg[j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
