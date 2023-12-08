/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:22:52 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/08 18:05:12 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw_square(t_square square, t_data *img)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < square.size && i + square.y < img->h)
	{
		j = 0;
		while (j < square.size && j + square.x < img->w)
		{
			put_pixel_data(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}

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

	mlx_key_hook(vars->win, close_mlx, vars);
	mlx_loop(vars->mlx);
	free(img);

	// check arguments
	// initialize mlx
	// initialize minirt
	// draw minirt
	// extra mlx
	// etc.
	return (0);
}
