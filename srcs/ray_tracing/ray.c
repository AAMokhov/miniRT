/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:10:34 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/22 15:31:38 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_ray	new_ray(t_point *origin, t_point *direction)
{
	t_ray	ray;

	ray.origin = *origin;
	ray.direction = *direction;
	ray.dot_direction = dot(direction, direction);
	return (ray);
}

t_point	ray_position(t_ray *ray, float distance)
{
	t_tuple tmp;

	tmp = multiply_on_scalar(&ray->direction, distance);
	return (add(&ray->origin, &tmp));
}
float 	radians(float degrees)
{
	return (degrees / 180 * M_PI);
}
