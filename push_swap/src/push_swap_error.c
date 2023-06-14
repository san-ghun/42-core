/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:41:00 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/14 14:03:07 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_printf("Error\n");
	return (1);
}

int	ft_str_isdigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_str_isinteger(char *str)
{
	return (1);
}

int	ft_str_isduplicate(char *str)
{
	return (1);
}

int	ft_iserror(char **arg)
{
	int	result;

	result = 0;
	return (result);
}
