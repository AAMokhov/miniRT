/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                              :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:04:55 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/24 01:15:49 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

float	closest_point_on_cylinder(t_figures *cy, t_ray *ray, float t1, float t2)
{
	t_vector	*or_to_centre;
	float		m1;
	float		m2;

	or_to_centre = ft_vec_subtract(&ray->origin, cy->fig.cy.centre);
	m1 = ft_vec_dotprod(&ray->direction, cy->normal) * t1;
	m1 += ft_vec_dotprod(or_to_centre, cy->normal);
	m2 = ft_vec_dotprod(&ray->direction, cy->normal) * t2;
	m2 += ft_vec_dotprod(or_to_centre, cy->normal);
	if (m1 > -cy->fig.cy.height / 2 && m1 < cy->fig.cy.height / 2)
	{
		if (m2 > -cy->fig.cy.height / 2 && m2 < cy->fig.cy.height / 2 && m1
			> m2)
			m1 = m2;
	}
	else if (m2 > -cy->fig.cy.height / 2 && m2 < cy->fig.cy.height / 2
		&& m1 < -cy->fig.cy.height / 2)
		m1 = m2;
	else
		m1 = MAXFLOAT;
	return (m1);
}

t_pair	ft_cy_intersect(void *is_ray, void	*is_cylinder)
{
	t_vector	*orig;
	t_figures	*cylinder;
	t_ray		*r;
	t_pair		roots;
	t_tuple		*tuple;

	cylinder = (t_figures *)is_cylinder;
	r = (t_ray *)is_ray;
	orig = ft_vec_subtract(&(r->origin), cylinder->fig.cy.centre);
	ft_vec_normalize(cylinder->normal);
	tuple = new_tuple(0, 0, 0, 0);
	tuple->x = r->dot_direction - powf(ft_vec_dotprod(&r->direction,
				cylinder->normal), 2);
	tuple->y = 2 * (ft_vec_dotprod(&r->direction, orig) - ft_vec_dotprod
			(&r->direction, cylinder->normal) * ft_vec_dotprod(orig,
				cylinder->normal));
	tuple->z = ft_vec_dotprod(orig, orig) - powf(ft_vec_dotprod(orig,
				cylinder->normal), 2) - powf(cylinder->fig.cy.radius, 2);
	roots = ft_quadratic_roots(tuple->x, tuple->y, tuple->z);
	free(tuple);
	if (roots.x == MAXFLOAT)
		return (roots);
	if (closest_point_on_cylinder(cylinder, r, roots.x, roots.y) == MAXFLOAT)
		roots.x = MAXFLOAT;
	return (roots);
}
