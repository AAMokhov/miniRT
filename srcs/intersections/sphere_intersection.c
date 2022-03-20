/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:04:33 by kclassie          #+#    #+#             */
/*   Updated: 2022/03/14 14:04:36 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_sp_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere)
{
	float		b;
	float		c;
	float		discr; //дискриминант: если >= 0, значит луч пересек сферу иликоснулся ее ребра
	// == 0 коснулся поверхности
	float		dist_1; //расстояние, где первый раз луч пересекается со сферой
	float		dist_2; //расстояние, где луч будет выходить из сферы
	t_vector	*cam_sphere;

	dist_1 = 0;
	dist_2 = 0;
	cam_sphere = ft_vec_subtraction(cam->origin, sphere->centre);
	b = 2 * (ft_vec_dotprod(cam_sphere, ray));
	c = ft_vec_dotprod(cam_sphere, cam_sphere) - pow(sphere->radius, 2);
	discr = (pow(b, 2) - 4 * c);
	free(cam_sphere);
	if (discr < 0)
		return (0); //нет пересечения со сферой
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) + sqrt(discr)) / 2; //TODO: нужно, если камера
	// находитсявнутри сферы
	if (dist_1 > 0) //сфера перед камерой
		return (1); //см. видео 4.2 с 06:20 - когда несколько объектов
	return(0);
}
