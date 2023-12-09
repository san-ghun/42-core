/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:57:57 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/09 11:36:23 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vars	*single_vars(void)
{
	static t_vars	this;
	static int		is_init;

	if (is_init)
		return (&this);
	this = (t_vars){
		.mlx = NULL,
		.win = NULL,
		.width = 0,
		.height = 0,
	};
	is_init = 1;
	return (&this);
}

t_vars	*new_program(int w, int h, char *str)
{
	t_vars	*vars;

	vars = single_vars();
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, w, h, str);
	vars->width = w;
	vars->height = h;
	return (vars);
}

t_data	*new_img(int w, int h, t_vars *vars)
{
	t_data	*this;

	this = (t_data *)malloc(sizeof(t_data));
	this->img = mlx_new_image(vars->mlx, w, h);
	this->addr = mlx_get_data_addr(\
		this->img, &(this->bits_per_pixel), \
		&(this->line_length), &(this->endian));
	this->w = w;
	this->h = h;
	return (this);
}
