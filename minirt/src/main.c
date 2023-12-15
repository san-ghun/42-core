/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:22:52 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/15 19:50:10 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_camera camera, t_container *container)
{
	int		i;
	int		j;
	int		sample;
	t_ray	ray;
	t_vec3	color_vec;
	double	scalev;
	t_interval	intensity;
	int		color;

	intensity = init_interval(0.000, 0.999);
	j = 0;
	while (j < camera.image_height)
	{
		i = 0;
		while (i < camera.image_width)
		{
			color_vec = init_vector(0, 0, 0);
			sample = 0;
			while (sample < camera.samples_per_pixel)
			{
				ray = get_ray(camera, i, j);
				color_vec = add(color_vec, ray_color(ray, single_rsc()->objs));
				// color_vec = ray_color(ray, single_rsc()->objs);
				sample++;
			}
			scalev = 1.0 / camera.samples_per_pixel;
			color_vec = scale(color_vec, scalev);
			color_vec.x = clamp(intensity, color_vec.x);
			color_vec.y = clamp(intensity, color_vec.y);
			color_vec.z = clamp(intensity, color_vec.z);
			color_vec = get_rgb(color_vec.x, color_vec.y, color_vec.z);
			color = get_trgb(0, (int)color_vec.x, (int)color_vec.y, (int)color_vec.z);
			put_pixel_data(container, i, j, color);
			i++;
		}
		j++;
	}
}

int	main(int argc, char *argv[])
{
	t_vars			*vars;
	t_container		*container;
	t_resource		*rsc;
	t_camera		cam;

	double	aspect_ratio = 16.0 / 9.0;
	int		image_w = 400;
	cam = init_camera(aspect_ratio, image_w);
	cam.samples_per_pixel = 100;

	rsc = new_resource(2);
	t_obj		*obj;
	t_sphere	*sphere;
	sphere = init_sphere(init_vector(0, -100.5, -1), 100);
	obj = init_obj((void *)sphere, SPHERE);
	append_obj(obj);
	sphere = init_sphere(init_vector(0.0, 0.0, -1.0), 0.5);
	obj = init_obj((void *)sphere, SPHERE);
	append_obj(obj);

	(void)argc;
	(void)argv;
	/// init window
	vars = new_program(cam.image_width, cam.image_height, "New Program");
	if (!(vars->mlx) || !(vars->win))
		return (1);
	/// init image
	container = new_container(vars->width, vars->height, vars);

	render(cam, container);

	mlx_put_image_to_window(vars->mlx, vars->win, container->img, 0, 0);

	/// hoooks
	mlx_hook(vars->win, 17, 0, close_mlx, container);
	mlx_key_hook(vars->win, key_hooks, container);
	mlx_mouse_hook(vars->win, mouse_hooks, container);
	mlx_loop(vars->mlx);

	return (0);
}
