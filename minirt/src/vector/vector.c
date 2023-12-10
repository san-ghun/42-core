/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:17:45 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/11 00:28:56 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	init_vector(double x, double y, double z)
{
	t_vec3	this;

	this.x = x;
	this.y = y;
	this.z = z;
	return (this);
}
