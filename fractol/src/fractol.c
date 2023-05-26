/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:02 by sanghupa          #+#    #+#             */
/*   Updated: 2023/05/26 16:57:22 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Exit the program as failure.
static void	ft_mlx_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	show_options(void)
{
	ft_printf("Arguments :\n");
	ft_printf("    Arg 1 : Choose a fractal #\n");
	ft_printf("        Julia................1\n");
	ft_printf("        Mandelbrot...........2\n");
	ft_printf("        Rabbit...............3\n");
	ft_printf("        Monster..............4\n");
	ft_printf("  (Optional) :\n");
	ft_printf("    Arg 2 : Iteration from 20 to 1000\n");
	ft_printf("    (For Julia Only) :\n");
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
		exit(0);
	}
}

// Print the window width and height.
// static void	ft_hook(void *param)
// {
// 	const mlx_t	*mlx = param;

// 	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

// Hook for key input
static void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	(void)param;
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

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fractol	f;

	if (argc >= 2)
	{
		choose_option(&f, argv);
		// MLX allows you to define its core behaviour before startup.
		mlx_set_setting(MLX_MAXIMIZED, true);
		mlx = mlx_init(WIDTH, HEIGHT, "42s", true);
		if (!mlx)
			ft_mlx_error();
		/* Do stuff */
		// Create and display the image.
		img = mlx_new_image(mlx, 256, 256);
		if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			ft_mlx_error();
		// Even after the image is being displayed, we can still modify the buffer.
		mlx_put_pixel(img, 0, 0, 0xFF0000FF);
		// Register a hook and pass mlx as an optional param.
		// NOTE: Do this before calling mlx_loop!
		mlx_key_hook(mlx, &ft_keyhook, NULL);
		// mlx_loop_hook(mlx, ft_hook, mlx);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
	else
	{
		ft_error_argc();
		show_options();
		exit(0);
	}
	return (EXIT_SUCCESS);
}
