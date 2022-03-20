/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:03:49 by kclassie          #+#    #+#             */
/*   Updated: 2022/03/14 14:03:52 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*ft_new_sphere(t_vector *centre, float	radius, t_color	*color)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		ft_error_exit(-1);
	sphere->centre = centre;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}
