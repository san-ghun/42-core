/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:22:52 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/07 21:10:50 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close_mlx(int keycode, t_vars *vars)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_data	img;

	(void)argc;
	(void)argv;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920 / 2, 1080 / 2, "Hello");
	img.img = mlx_new_image(vars.mlx, 1920 / 2, 1080 / 2);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_key_hook(vars.win, close_mlx, &vars);
	mlx_loop(vars.mlx);

	// check arguments
	// initialize mlx
	// initialize minirt
	// draw minirt
	// extra mlx
	// etc.
	return (0);
}
