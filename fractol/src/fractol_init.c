/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:39:56 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/02 15:40:54 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol, char **av)
{
	fractol->fractal.xr = -2.0;
	fractol->fractal.yi = -2.0;
	if (fractol->fractal.type == 2)
	{
		fractol->fractal.xr = -2.5;
		fractol->fractal.yi = -2.0;
	}
	fractol->fractal.iteration = 50;
	if (av[2])
		fractol->fractal.iteration = ft_atoi(av[2]);
	fractol->fractal.cr = 0;
	fractol->fractal.ci = 0;
	if (av[3] && av[4])
	{
		fractol->fractal.cr = ft_atof(av[3]);
		fractol->fractal.ci = ft_atof(av[4]);
	}
	fractol->fractal.scale = 200.00;
	fractol->rgba.r = 0x42;
	fractol->rgba.g = 0x32;
	fractol->rgba.b = 0x22;
	fractol->rgba.a = 0xFF;
	fractol->fractal.height = 0;
	fractol->fractal.width = 0;
}

int	julia(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	zi = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.yi;
	zr = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.xr;
	cr = -0.8;
	ci = 0.156;
	if (fractol->fractal.ci != 0)
	{
		cr = fractol->fractal.cr;
		ci = fractol->fractal.ci;
	}
	while ((zr * zr) + (zi * zi) < 4 && \
			fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractol->fractal.depth += 1;
	}
	return (fractol->fractal.depth);
}

int	mandelbrot(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	zr = 0;
	zi = 0;
	ci = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.yi;
	cr = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.xr;
	while ((zr * zr) + (zi * zi) < 4 \
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractol->fractal.depth += 1;
	}
	return (fractol->fractal.depth);
}

int	rabbit(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	zi = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.yi;
	zr = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.xr;
	cr = -0.123;
	ci = 0.745;
	if (fractol->fractal.ci != 0)
	{
		cr = fractol->fractal.cr;
		ci = fractol->fractal.ci;
	}
	while ((zr * zr) + (zi * zi) < 4 && \
			fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractol->fractal.depth += 1;
	}
	return (fractol->fractal.depth);
}

int	san_marco(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	zi = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.yi;
	zr = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.xr;
	cr = -0.75;
	ci = 0.0;
	if (fractol->fractal.ci != 0)
	{
		cr = fractol->fractal.cr;
		ci = fractol->fractal.ci;
	}
	while ((zr * zr) + (zi * zi) < 4 && \
			fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractol->fractal.depth += 1;
	}
	return (fractol->fractal.depth);
}
