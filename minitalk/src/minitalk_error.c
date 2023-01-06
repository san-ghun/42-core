/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:55:32 by sanghupa          #+#    #+#             */
/*   Updated: 2023/01/06 16:12:03 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	printf("Error: Invalid argument - PID\n");
	return (1);
}

int	ft_error_argc(void)
{
	printf("Error: Invalid argument - argument list\n");
	return (1);
}
