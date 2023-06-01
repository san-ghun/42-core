/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:02 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/01 17:39:16 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Exit the program as failure.
static void	ft_mlx_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	show_options(void)
{
	ft_printf("Arguments :\n");
	ft_printf("    Arg 1 : Choose a fractal #\n");
	ft_printf("        Julia................1\n");
	ft_printf("        Mandelbrot...........2\n");
	ft_printf("        Rabbit...............3\n");
	ft_printf("        Monster..............4\n\n");
	ft_printf("  (Optional) :\n");
	ft_printf("    Arg 2 : Iteration from 20 to 1000\n\n");
	ft_printf("  (For Julia Only) :\n");
	ft_printf("    Arg 3 : Real complex number\n");
	ft_printf("    Arg 4 : Imaginary complex number\n\n");
	ft_printf("Commands :\n");
	ft_printf("    ESC..................Quit\n");
	ft_printf("    Space................Change Color\n");
	ft_printf("    Scroll up............Zoom in\n");
	ft_printf("    Scroll down..........Zoom out\n\n");
}

static void	choose_option(t_fractol *f, char **av)
{
	if (av[1][0] == '1' && av[1][1] == '\0')
		f->fractal.type = 1;
	else if (av[1][0] == '2' && av[1][1] == '\0')
		f->fractal.type = 2;
	else if (av[1][0] == '3' && av[1][1] == '\0')
		f->fractal.type = 3;
	else if (av[1][0] == '4' && av[1][1] == '\0')
		f->fractal.type = 4;
	else
	{
		ft_error_argv();
		show_options();
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc >= 2)
	{
		choose_option(&f, argv);
		// MLX allows you to define its core behaviour before startup.
		// mlx_set_setting(MLX_MAXIMIZED, true);
		f.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
		if (!f.mlx)
			ft_mlx_error();
		/* Do stuff */
		// Create and display the image.
		f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
		if (!f.img || (mlx_image_to_window(f.mlx, f.img, 0, 0) < 0))
		{
			mlx_close_window(f.mlx);
			ft_mlx_error();
		}
		// Even after the image is being displayed, we can still modify the buffer.
		// mlx_put_pixel(f.img, WIDTH/2, HEIGHT/2, 0xFF0000FF);
		init_fractol(&f, argv);
		draw_fractol(&f);
		
		// Register a hook and pass mlx as an optional param.
		// NOTE: Do this before calling mlx_loop!
		mlx_key_hook(f.mlx, &ft_keyhook_general, f.mlx);
		mlx_loop_hook(f.mlx, ft_hook, &f);
		mlx_loop(f.mlx);
		mlx_terminate(f.mlx);
	}
	else
	{
		ft_error_argc();
		show_options();
	}
	return (EXIT_SUCCESS);
}
