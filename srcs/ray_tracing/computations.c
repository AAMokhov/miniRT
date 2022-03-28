/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:24:00 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/24 01:16:59 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	new_hit(t_scene *scene, t_ray *ray)
{
	t_hit		h;
	t_list		*ls_ptr;
	t_figures	*object;
	float		min_distance;

	ls_ptr = scene->ls_head_fig;
	min_distance = FLT_MAX;
	h.object = NULL;
	while (ls_ptr)
	{
		object = (t_figures *)ls_ptr->content;
		t_pair pair = run_intersect(ray, object);
		if (pair.x < min_distance && pair.x != FLT_MAX && pair.x >= 0) {
			min_distance = pair.x;
			h.object = object;
			h.pair = pair;
		}
		ls_ptr = ls_ptr->next;
	}
	return (h);
}

void	prepare_computations(t_comp *computations, t_scene *scene, t_ray *ray)
{
	t_hit	hit;

	hit = new_hit(scene, ray);
	if (!hit.object)
	{
		computations->object = NULL;
		return ;
	}
	computations->ray = ray;
	computations->object = hit.object;
	computations->t1 = hit.pair.x;
	computations->t2 = hit.pair.y;
	computations->point = ray_position(ray, computations->t1);
	computations->eye_v = multiply_on_scalar(&(ray->direction), -1);
	computations->normal = run_normal_at(computations->object, computations);

	if (ft_vec_add(computations->normal, computations->eye_v) < 0)
		computations->normal = multiply_on_scalar(computations->normal, -1);

	computations->reflect_v = reflect(&(ray->direction), computations->normal);
	ft_vec_normalize(computations->reflect_v);
	computations->over_point = multiply_on_scalar(computations->normal, EPSILON);
	computations->over_point = ft_vec_add(computations->point, computations->over_point);
}
