/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:47:39 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/14 21:58:59 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

/*
** =============================================================================
** Dependency
** =============================================================================
*/

#include "ray.h"
#include "libft.h"

/*
** =============================================================================
** Type Definition
** =============================================================================
*/

typedef struct s_sphere
{
    t_vec3      center;
    double      radius;
}               t_sphere;

typedef struct s_obj
{
    int         id;
    int         type;
    int         nth;
    void        *data;
}               t_obj;

typedef struct s_hit
{
    t_vec3      point;
    t_vec3      normal;
    double      t;
    t_bool      front_face;
}               t_hit;


/*
** =============================================================================
** Function
** =============================================================================
*/

t_obj   	*init_obj(void *data, int type);

t_hit	    init_rec(void);
void	    set_face_normal(t_hit *rec, t_ray ray, t_vec3 outward_normal);
t_bool  	hit_objs(t_obj *objs[], t_ray ray, double r_tmin, double r_tmax, t_hit *rec);

t_sphere	*init_sphere(t_vec3 center, double radius);
t_bool	    hit_sphere(void *sphere, t_ray ray, double r_tmin, double r_tmax, t_hit *rec);

#endif
