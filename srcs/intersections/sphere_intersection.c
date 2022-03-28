/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:04:55 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/24 01:15:49 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pair	ft_quadratic_roots(float a, float b, float c)
{
	float	d;
	t_pair	point;

	d = (b * b) - (4 * c * a);
	point.x = FLT_MAX;
	point.y = FLT_MAX;
	if (d >= 0)
	{
		point.x = (-b + sqrt(d)) / (2 * a);
		point.y = (-b - sqrt(d)) / (2 * a);
		if (point.x > point.y && point.x >= 0 && point.y >= 0)
		{
			d = point.x;
			point.x = point.y;
			point.y = d;
		}
	}
	if (d < 0)
	{
		point.x = MAXFLOAT;
		point.y = MAXFLOAT;
	}
	return (point);
}

t_pair	ft_sph_intersect(void *is_ray, void *is_sphere)
{
	// t_camera	*cam;
	// t_vector	*ray;
	// t_figures	*sphere;
	// t_pair		res;
	// float		b;
	// float		c;
	// float		discr; //дискриминант: если >= 0, значит луч пересек сферу иликоснулся ее ребра
	// t_vector	*cam_sphere;

	// res.x = 0;
	// res.y = 0;
	// cam = (t_camera *)is_cam;
	// ray = (t_vector *)is_ray;
	// sphere = (t_figures *)is_sphere;
	// cam_sphere = ft_vec_subtract(cam->origin, sphere->fig.sp.centre);
	// b = 2 * ft_vec_dotprod(cam_sphere, ray);
	// c = ft_vec_dotprod(cam_sphere, cam_sphere) - pow(sphere->fig.sp.radius, 2);
	// discr = (pow(b, 2) - 4 * c);
	// free(cam_sphere);
	// if (discr < 0)
	// 	return (res); //нет пересечения со сферой
	// res.x = ((b * (-1)) - sqrt(discr)) / 2;
	// res.y = ((b * (-1)) + sqrt(discr)) / 2; //нужно, если камера находитсявнутри сферы
	// return(res);
	t_vector	*origin_to_center;
	t_figures	*sphere;
	t_ray 		*r;

	sphere = (t_figures *)is_sphere;
	r = (t_ray *)is_ray;
	origin_to_center = ft_vec_subtract(&(r->origin), sphere->fig.sp.centre);

	return (ft_quadratic_roots(
								r->dot_direction,
								2 * ft_vec_dotprod(&(r->direction), origin_to_center),
								ft_vec_dotprod(origin_to_center, origin_to_center) - (float)pow(sphere->fig.sp.radius, 2)));
}

t_pair	run_intersect(void *ray, t_figures *fig)
{
	return (fig->intersection_func(ray, fig));
}
