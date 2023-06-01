/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:11:53 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/01 22:36:57 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	randomize_color(t_rgba *color)
{
	color->r = rand() % 0xFF;
	color->g = rand() % 0xFF;
	color->b = rand() % 0xFF;
	color->a = rand() % 0xFF;
}

void	display_info(t_fractol *f)
{
	char	*num;
	char	*str;

	num = ft_itoa(f->fractal.iteration);
	str = ft_strjoin("Number of iterations : ", num);
	mlx_put_string(f->mlx, str, 15, 10);
	free(num);
	free(str);
	num = ft_itoa((int)f->fractal.scale);
	str = ft_strjoin("Scale value : ", num);
	mlx_put_string(f->mlx, str, 15, 30);
	free(num);
	free(str);
}

void	put_pixel(t_fractol *f, int depth)
{
	int	color;

	color = ft_pixel(f->rgba.r + (depth * 2), \
						f->rgba.g + (depth * 4), \
						f->rgba.b + (depth * 3), \
						f->rgba.a);
	if (f->fractal.height < WIDTH && \
			f->fractal.width < HEIGHT && \
			depth == f->fractal.iteration)
		mlx_put_pixel(f->img, f->fractal.width, f->fractal.height, 0x00);
	else if (f->fractal.height < WIDTH && f->fractal.width < HEIGHT)
		mlx_put_pixel(f->img, f->fractal.width, f->fractal.height, color);
}

int	draw_fractol(t_fractol *f)
{
	int		depth;
	double	tmp_width;

	tmp_width = f->fractal.width;
	while (f->fractal.height < WIDTH)
	{
		f->fractal.width = tmp_width;
		while (f->fractal.width < WIDTH)
		{
			if (f->fractal.type == 1)
				depth = julia(f);
			else if (f->fractal.type == 2)
				depth = mandelbrot(f);
			else if (f->fractal.type == 3)
				depth = rabbit(f);
			else if (f->fractal.type == 4)
				depth = monster(f);
			put_pixel(f, depth);
			f->fractal.width += 1;
		}
		f->fractal.height += 1;
	}
	mlx_image_to_window(f->mlx, f->img, 0, 0);
	display_info(f);
	return (0);
}
