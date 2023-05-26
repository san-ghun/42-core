/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:17:35 by sanghupa          #+#    #+#             */
/*   Updated: 2023/05/26 16:11:15 by sanghupa         ###   ########.fr       */
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
	ft_printf("\nError: Invalid argument - argv\n\n");
	return (1);
}

int	ft_error_argc(void)
{
	ft_printf("\nError: Invalid argument - argc\n\n");
	return (1);
}
