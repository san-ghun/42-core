/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:41:00 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/29 11:23:24 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_printf("Error\n");
	return (1);
}

int	ft_iserror(char *arg[])
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (arg[i] != NULL)
	{
		result += ft_str_isdigit(arg[i]);
		result += ft_str_isinteger(arg[i]) * 100;
		i++;
	}
	result += ft_str_isduplicate(arg) * 10000;
	ft_printf("error result = %d\n", result);
	return (result);
}
