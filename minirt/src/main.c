/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:22:52 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/08 14:33:15 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		h;
	int		w;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
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

t_vars	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_vars){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_data	img;

	(void)argc;
	(void)argv;
	vars = new_program(300, 300, "New Program");
	if (!vars.mlx || !vars.win)
		return (1);
	else 
	{
		img.img = mlx_new_image(vars.mlx, 4, 4);
		img.addr = mlx_get_data_addr(\
			img.img, &(img.bits_per_pixel), \
			&(img.line_length), &(img.endian));
		img.w = 4;
		img.h = 4;
		printf("img_ptr		: [%p]\n", img.img);
		printf("bpp		: [%d]\n", img.bits_per_pixel);
		printf("line_len	: [%d]\n", img.line_length);
		printf("endian		: [%d]\n", img.endian);
		printf("addr		: [%p]\n", img.addr);
	}
	my_mlx_pixel_put(&img, 2, 2, 0x00FF0000);
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
