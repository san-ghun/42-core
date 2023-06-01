/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:37:50 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/01 17:39:04 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Print the window width and height.
void	ft_hook(void* param)
{
	t_fractol *f;

	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	if (mlx_is_key_down(f->mlx, MLX_KEY_SPACE))
		randomize_color(&f->rgba);
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
		f->fractal.yi -= 10 / f->fractal.scale;
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		f->fractal.yi += 10 / f->fractal.scale;
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		f->fractal.xr -= 10 / f->fractal.scale;
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		f->fractal.xr += 10 / f->fractal.scale;
	f->fractal.height = 0;
	f->fractal.width = 0;
	draw_fractol(f);
}

// Hook for key input
void	ft_keyhook_general(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");
	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");
	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}
