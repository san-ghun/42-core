/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:23 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/02 15:43:32 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# include "ft_printf.h"

# include <stdio.h>
# include <ctype.h>

# define WIDTH		800
# define HEIGHT		800
# define ZOOMRATE	1.2
# define ISITER		false
# define ITER		2

typedef struct s_rgba
{
	int		r;
	int		g;
	int		b;
	int		a;
}				t_rgba;

typedef struct s_type
{
	int		type;
	int		depth;
	int		iteration;
	double	width;
	double	height;
	double	scale;
	double	xr;
	double	yi;
	double	cr;
	double	ci;
}				t_type;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_rgba		rgba;
	t_type		fractal;
}				t_fractol;

/* fractol.c */

void	show_options(void);

void	choose_option(t_fractol *f, char **av);

void	init_fractolmlx(t_fractol *f);

/* fractol_init.c */

void	init_fractol(t_fractol *fractol, char **av);

int		julia(t_fractol *fractol);

int		mandelbrot(t_fractol *fractol);

int		rabbit(t_fractol *fractol);

int		san_marco(t_fractol *fractol);

/* fractol_draw.c */

int		ft_pixel(int r, int g, int b, int a);

void	randomize_color(t_rgba *color);

void	display_info(t_fractol *f);

void	put_pixel(t_fractol *f, int depth);

int		draw_fractol(t_fractol *f);

/* fractol_control.c */

void	ft_hook(void *param);

void	zoom_in(int x, int y, t_fractol *f);

void	zoom_out(int x, int y, t_fractol *f);

void	ft_scrollhook(double xdelta, double ydelta, void *param);

/* fractol_utils.c */

double	ft_atof(const char *str);

/* fractol_error.c */

int		ft_str_isdigit(char *str);

int		ft_error_argv(void);

int		ft_error_argc(void);

void	ft_mlx_error(void);

#endif
