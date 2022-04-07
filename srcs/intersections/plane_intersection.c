/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                                 :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:04:55 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/24 01:15:49 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pair	ft_pl_intersect(void *is_ray, void *is_plane)
{
	t_figures	*plane;
	t_ray		*r;
	t_vector	*origin_to_center;
	t_vector	*orientation;
	t_pair		*pair;

	pair = (t_pair *)enh_malloc(sizeof (t_pair));
	plane = (t_figures *)is_plane;
	r = (t_ray *)is_ray;
	origin_to_center = ft_vec_subtract(&(r->origin), plane->fig.pl.centre);
	orientation = plane->normal;
	pair->y = ft_vec_dotprod(orientation, &(r->direction));
	if (pair->y < 0)
	{
		orientation = multiply_on_scalar(plane->normal, -1);
		pair->y = ft_vec_dotprod(orientation, &(r->direction));
	}
	pair->x = ft_vec_dotprod(orientation, origin_to_center);
	if (pair->y != 0 && ((pair->x > 0 && pair->y < 0) || (pair->x < 0
				&& pair->y > 0)))
		return ((t_pair){-pair->x / pair->y, FLT_MAX});
	return ((t_pair){FLT_MAX, FLT_MAX});
}
