/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:15:54 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/08 17:28:08 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel_data(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < data->w && y < data->h)
	{
		dst = data->addr + \
			(y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
