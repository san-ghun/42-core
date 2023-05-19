/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:02 by sanghupa          #+#    #+#             */
/*   Updated: 2023/05/19 13:02:24 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_target_error(int request, int response, int f(void))
{
	int		err;
	char	*res_msg;

	err = f();
	if (!response)
	{
		res_msg = "Result: target request %d failed with response\n";
		ft_printf(res_msg, request);
	}
	if (!request)
	{
		res_msg = "Result: target request %d failed with response #%d\n";
		ft_printf(res_msg, request, response);
	}
	ft_printf("Try: {recommendation message}\n");
	return (err);
}

int	main(int argc, char **argv)
{
	mlx_t*	mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	// Gotta error check this stuff
	if (!(mlx))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	(void)argc;
	(void)argv;
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
