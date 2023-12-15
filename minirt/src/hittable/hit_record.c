/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:25:50 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/15 15:18:31 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

t_hit	init_rec(void)
{
	t_hit	this;

	this.front_face = 0;
	this.normal = init_vector(0, 0, 0);
	this.point = init_vector(0, 0, 0);
	this.t = 0;
	return (this);
}

void	set_face_normal(t_hit *rec, t_ray ray, t_vec3 outward_normal)
{
	rec->front_face = dot(ray.direction, outward_normal) < 0;
	if (rec->front_face)
		rec->normal = outward_normal;
	else
		rec->normal = flip(outward_normal);
}

t_bool	hit_objs(t_obj *objs[], t_ray ray, t_interval interval, t_hit *rec)
{
	// t_hit	temp_rec;
	t_bool	hit_anything = 0;
	double	closest_so_far = interval.max;

	int	i = 0;
	while (objs[i] != NULL)
	{
		t_interval	ray_t = init_interval(interval.min, closest_so_far);
		// may change data to void pointer and notate TYPE value in new struct
		if (hit_sphere((void *)(objs[i]->data), ray, ray_t, rec))
		{
			hit_anything = 1;
			closest_so_far = rec->t;
			// temp_rec.t;
			// rec->front_face = temp_rec.front_face;
			// rec->normal = temp_rec.normal;
			// rec->point = temp_rec.point;
			// rec->t = temp_rec.t;
			// printf("%f, %f, %f\n", rec->normal.x, rec->normal.y, rec->normal.z);
		}
		i++;
	}
	return (hit_anything);
}
