/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainrt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:22:52 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/11 00:36:34 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	get_rgb(double red, double green, double blue)
{
	red *= 255.999;
	green *= 255.999;
	blue *= 255.999;
	return ((t_vec3){red, green, blue});
}

double	hit_sphere(t_vec3 center, double radius, t_ray ray)
{
	t_vec3	oc = subtract(ray.origin, center);
	double 	a = dot(ray.direction, ray.direction);
	double	b = 2.0 * dot(oc, ray.direction);
	double	c = dot(oc, oc) - radius * radius;
	double	discriminant = b * b - 4 * a * c;
	
	// double 	a = len_sqrt(ray.direction);
	// double	half_b = dot(oc, ray.direction);
	// double	c = len_sqrt(oc) - radius * radius;
	// double	discriminant = half_b * half_b - a * c;
	
	if (discriminant < 0)
		return (-1.0);
	else
		return ((- b - sqrt(discriminant)) / (2.0 * a));
		// return ((-half_b - sqrt(discriminant)) / a);
}

int	ray_color(t_ray ray)
{
	t_vec3	color;
	double	t;

	t = hit_sphere((t_vec3){0, 0, -1}, 0.5, ray);
	if (t > 0.0)
	{
		t_vec3	N = unit(subtract(ray_at(ray, t), (t_vec3){0, 0, -1}));
		color = scale(get_rgb(N.x + 1, N.y + 1, N.z + 1), 0.5);
	}
	else
	{
		t_vec3	unit_direction = unit(ray.direction);
		double	a = 0.5 * (unit_direction.y + 1.0);
		color = scale(get_rgb(1.0, 1.0, 1.0), 1.0 - a);
		color = add(color, scale(get_rgb(0.5, 0.7, 1.0), a));
	}
	return (get_trgb(0, (int)color.x, (int)color.y, (int)color.z));
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;
	t_data	*img;

	double	aspect_ratio = 16.0 / 9.0;
	int		image_w = 400;
	int		image_h = (int)(image_w / aspect_ratio);

	double	focal_len = 1.0;
	double	viewport_h = 2.0;
	double	viewport_w = viewport_h * aspect_ratio;
	t_vec3	camera_center = (t_vec3){0, 0, 0};

	t_vec3	viewport_u = (t_vec3){viewport_w, 0, 0};
	t_vec3	viewport_v = (t_vec3){0, -viewport_h, 0};

	t_vec3	pixel_delta_u = scale(viewport_u, (double)(1 / (double)image_w));
	t_vec3	pixel_delta_v = scale(viewport_v, (double)(1 / (double)image_h));

	t_vec3	viewport_upper_left = (t_vec3){
		camera_center.x - 0,
		camera_center.y - 0,
		camera_center.z - focal_len,
	};
	viewport_upper_left = subtract(viewport_upper_left, scale(viewport_u, 0.5));
	viewport_upper_left = subtract(viewport_upper_left, scale(viewport_v, 0.5));
	
	t_vec3	pixel00_loc = (t_vec3){
		viewport_upper_left.x + 0.5 * (pixel_delta_u.x + pixel_delta_v.x),
		viewport_upper_left.y + 0.5 * (pixel_delta_u.y + pixel_delta_v.y),
		viewport_upper_left.z + 0.5 * (pixel_delta_u.z + pixel_delta_v.z),
	};

	(void)argc;
	(void)argv;
	/// init window
	vars = new_program(image_w, image_h, "New Program");
	if (!(vars->mlx) || !(vars->win))
		return (1);
	/// init image
	img = new_img(vars->width, vars->height, vars);

	/// init rt and draw
	int	i;
	int	j;
	int	color;

	j = 0;
	while (j < image_h)
	{
		i = 0;
		while (i < image_w)
		{
			t_vec3	pixel_center = add(pixel00_loc, scale(pixel_delta_u, (double)i));
			pixel_center = add(pixel_center, scale(pixel_delta_v, (double)j));
			t_vec3	ray_direction = subtract(pixel_center, camera_center);
			t_ray	r = (t_ray){
				.origin = camera_center,
				.direction = ray_direction,
			};
			color = ray_color(r);
			put_pixel_data(img, i, j, color);
			i++;
		}
		j++;
	}

	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	
	/// hoooks
	mlx_hook(vars->win, 17, 0, close_mlx, img);
	mlx_key_hook(vars->win, key_hooks, img);
	mlx_mouse_hook(vars->win, mouse_hooks, img);
	mlx_loop(vars->mlx);

	return (0);
}
