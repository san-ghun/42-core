/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:22:52 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/08 20:44:15 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_vars	*vars;
	t_data	*img;

	(void)argc;
	(void)argv;
	vars = new_program(300, 300, "New Program");
	if (!(vars->mlx) || !(vars->win))
		return (1);
	img = new_img(300, 300, vars);
	draw_square((t_square){20, 20, 260, 0x0000FF}, img);
	put_pixel_data(img, 150, 150, 0x00FFFFF);
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
