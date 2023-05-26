/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:23 by sanghupa          #+#    #+#             */
/*   Updated: 2023/05/26 15:15:25 by sanghupa         ###   ########.fr       */
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
	mlx_t	mlx;
	t_rgba	rgba;
	t_type	fractol;
}				t_fractol;

/* fractol_val_input.c */

/* fractol_error.c */

int	ft_str_isdigit(char *str);

int	ft_error_argv(void);

int	ft_error_argc(void);

/* fractol.c */

#endif