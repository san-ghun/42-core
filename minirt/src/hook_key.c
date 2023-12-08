/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:01:26 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/08 20:00:14 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_mlx(int keycode, t_data *img);
int	get_color(void);

int	key_hooks(int keycode, t_data *img)
{
	t_vars	*vars;

	vars = single_vars();
	if (keycode == K_ESC)
		close_mlx(K_ESC, img);
	else if (keycode == K_SP)
		draw_square((t_square){0, 0, img->w, 0xFFFFFF}, img);
	// else if (keycode == K_R)
	// 	color = get_color();
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	return (0);
}

int	close_mlx(int keycode, t_data *img)
{
	t_vars	*vars;

	vars = single_vars();
	if (keycode == K_ESC)
	{
		mlx_destroy_image(vars->mlx, img->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(img);
		free(vars->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	get_color(void)
{
	return (rand() % INTMAX);
}
