/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:39:56 by sanghupa          #+#    #+#             */
/*   Updated: 2023/05/31 17:36:44 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *f, char **av)
{
	f->fractal.xr = -2.0;
	f->fractal.yi = -1.30;
	if (f->fractal.type == 2)
	{
		f->fractal.xr = -2.5;
		f->fractal.yi = -1.30;
	}
	f->fractal.iteration = 50;
	if (av[2])
		f->fractal.iteration = ft_atoi(av[2]);
	f->fractal.cr = 0;
	f->fractal.ci = 0;
	if (av[3] && av[4])
	{
		f->fractal.cr = ft_atof(av[3]);
		f->fractal.ci = ft_atof(av[4]);
	}
	f->fractal.scale = 300.00;
	f->rgba.r = 0x42;
	f->rgba.g = 0x32;
	f->rgba.b = 0x22;
	f->fractal.height = 0;
	f->fractal.width = 0;
}

int	julia(t_fractol *f)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	f->fractal.depth = 0;
	zi = f->fractal.width / f->fractal.scale + f->fractal.yi;
	zr = f->fractal.height / f->fractal.scale + f->fractal.xr;
	cr = -0.8;
	ci = 0.156;
	if (f->fractal.ci != 0)
	{
		cr = f->fractal.cr;
		ci = f->fractal.ci;
	}
	while ((zr * zr) + (zi * zi) < 4 && f->fractal.depth \
	 < f->fractal.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		f->fractal.depth += 1;
	}
	return (f->fractal.depth);
}