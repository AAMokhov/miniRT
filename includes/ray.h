/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:21:59 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/22 20:13:33 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

# include "minirt.h"
# include "tuple.h"

struct s_ray
{
	t_tuple 	origin;
	t_tuple 	direction;
	float		dot_direction;
};

typedef struct s_ray	t_ray;

t_ray		new_ray(t_point *origin, t_point *direction);
t_point		*ray_position(t_ray *ray, float distance);
t_ray		transform(t_ray *ray, t_matrix *matrix);
float		closest_point_on_cylinder(t_figures *cy, t_ray *ray, float t1,
									   float t2);

#endif
