/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:02 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/02 15:14:06 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_options(void)
{
	ft_printf("Arguments :\n");
	ft_printf("    Arg 1 : Choose a fractal #\n");
	ft_printf("        Julia................1\n");
	ft_printf("        Mandelbrot...........2\n");
	ft_printf("        Rabbit...............3\n");
	ft_printf("        San Marco............4\n\n");
	ft_printf("  (Optional) :\n");
	ft_printf("    Arg 2 : Iteration from 20 to 1000\n\n");
	ft_printf("  (For Julia & Rabbit & San Marco) :\n");
	ft_printf("    Arg 3 : Real complex number\n");
	ft_printf("    Arg 4 : Imaginary complex number\n\n");
	ft_printf("Commands :\n");
	ft_printf("    ESC..................Quit\n");
	ft_printf("    Space................Change Color\n");
	ft_printf("    Scroll up............Zoom in\n");
	ft_printf("    Scroll down..........Zoom out\n\n");
}

void	choose_option(t_fractol *f, char **av)
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

void	init_fractolmlx(t_fractol *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!f->mlx)
		ft_mlx_error();
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
	{
		mlx_close_window(f->mlx);
		ft_mlx_error();
	}
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc >= 2)
	{
		choose_option(&f, argv);
		init_fractolmlx(&f);
		init_fractol(&f, argv);
		draw_fractol(&f);
		mlx_loop_hook(f.mlx, ft_hook, &f);
		mlx_scroll_hook(f.mlx, ft_scrollhook, &f);
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
