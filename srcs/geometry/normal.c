/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:05:54 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/23 20:26:04 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*run_normal_at(t_figures *this, void *computations)
{
	return (this->normal_func(this, computations));
}

t_vector	*normal_at_sphere(void *this, void *computations)
{
	t_comp		*comp;
	t_figures	*sphere;
	t_vector	*normal;

	sphere = (t_figures *)this;
	comp = (t_comp *)computations;
	normal = ft_vec_subtract(comp->point, sphere->fig.sp.centre);
	ft_vec_normalize(normal);
	return (normal);
}

t_vector	*normal_at_plane(void *this, void *computations)
{
	t_comp		*comp;
	t_figures	*plane;
	t_vector	*normal;

	plane = (t_figures *)this;
	comp = (t_comp *)computations;
	if (ft_vec_dotprod(plane->normal, comp->eye_v) < 0)
		normal = multiply_on_scalar(plane->normal, -1);
	else
		normal = plane->normal;
	ft_vec_normalize(normal);
	return (normal);
}

t_vector	*normal_at_cylinder(void *this, void *computations)
{
	t_comp		*comp;
	t_figures	*cylinder;
	t_vector	*normal;
	t_tuple		*a;
	float		closest_dist;

	cylinder = (t_figures *)this;
	comp = (t_comp *)computations;
	closest_dist = closest_point_on_cylinder(cylinder, comp->ray, comp->t1,
			comp->t2);
	a = multiply_on_scalar(cylinder->normal, closest_dist);
	a = ft_vec_add(cylinder->fig.cy.centre, a);
	normal = ft_vec_subtract(comp->point, a);
	ft_vec_normalize(normal);
	return (normal);
}
