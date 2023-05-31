/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:23 by sanghupa          #+#    #+#             */
/*   Updated: 2023/05/31 17:33:23 by sanghupa         ###   ########.fr       */
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

# define WIDTH 512
# define HEIGHT 512

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
	t_rgba	rgba;
	t_type	fractal;
}				t_fractol;

/* fractol_error.c */

int	ft_str_isdigit(char *str);

int	ft_error_argv(void);

int	ft_error_argc(void);

/* fractol_init.c */

void	init_fractol(t_fractol *f, char **av);

/* fractol_draw.c */

/* fractol_utils.c */

/* fractol.c */

#endif