/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:15:54 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/10 19:48:25 by sanghupa         ###   ########.fr       */
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

void	draw_square(t_square square, t_data *img)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < square.size && i + square.y < img->h)
	{
		j = 0;
		while (j < square.size && j + square.x < img->w)
		{
			color = get_trgb(1, i, j, 0);
			put_pixel_data(img, j + square.x, i + square.y, color);
			j++;
		}
		i++;
	}
}

t_temp	*single_temp(void)
{
	static t_temp	this;
	static int		is_init;

	if (is_init)
		return (&this);
	this = (t_temp){
		.size = 10,
		.color = 0xFFFFFF,
	};
	is_init = 1;
	return (&this);
}
