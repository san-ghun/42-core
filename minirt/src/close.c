/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:17:42 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/14 21:28:47 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_free_2d(void **targets)
{
	int	i;

	i = -1;
	while (targets[++i])
		free(targets[i]);
	free(targets);
	targets = NULL;
}

int	close_mlx(t_container *img)
{
	t_vars		*vars;
	t_resource	*rsc;

	vars = single_vars();
	rsc = single_rsc();
	mlx_destroy_image(vars->mlx, img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	/// NOT available in MacOS
	/// Un-comment following if you are compiling on Linux
	// mlx_destroy_display(vars->mlx);
	ft_free_2d((void **)rsc->objs);
	free(img);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}
