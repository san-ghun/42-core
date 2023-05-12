/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:17:35 by sanghupa          #+#    #+#             */
/*   Updated: 2023/05/12 16:18:32 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_str_isdigit(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_error_argv(void)
{
	ft_printf("Error: Invalid argument - argv\n");
	return (1);
}

int	ft_error_argc(void)
{
	ft_printf("Error: Invalid argument - argc\n");
	return (1);
}
