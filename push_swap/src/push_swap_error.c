/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:41:00 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/07 22:38:50 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_printf("Error\n");
	return (1);
}

int	ft_iserror(char *arg[], int len)
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
	if (result > 0)
	{
		i = 0;
		while (i < len)
			free(arg[i++]);
		free(arg);
	}
	return (result);
}
