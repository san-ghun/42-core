/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:22:52 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/09 17:00:47 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_vars	*vars;
	t_data	*img;

	(void)argc;
	(void)argv;
	vars = new_program(256, 256, "New Program");
	if (!(vars->mlx) || !(vars->win))
		return (1);
	img = new_img(256, 256, vars);
	draw_square((t_square){0, 0, 256, 0x0000FF}, img);
	put_pixel_data(img, 256 / 2, 256 / 2, 0x00FFFFF);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_hook(vars->win, 17, 0, close_mlx, img);
	mlx_key_hook(vars->win, key_hooks, img);
	mlx_mouse_hook(vars->win, mouse_hooks, img);
	mlx_loop(vars->mlx);
	// check arguments
	// initialize mlx
	// initialize minirt
	// draw minirt
	// extra mlx
	// etc.
	return (0);
}
