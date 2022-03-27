/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:43:12 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/27 18:45:57 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void 	apply_light(t_light *light, t_color *color, t_comp *computations)
{
	t_vector	*light_ray;
	t_color		*diffuse;
	float		cosine;
	float		distance;

	light_ray = ft_vec_subtract(light->origin, computations->point);
	distance = pow(0.9, ft_vec_len(light_ray));
	ft_vec_normalize(light_ray);

	diffuse = new_tuple(0, 0, 0, COLOR);

	cosine = ft_vec_dotprod(light_ray, computations->normal);
	if (cosine >= 0)
		diffuse = multiply_on_scalar(&(light->color), cosine * distance);
	*color = ft_color_addition(color, diffuse);
}

static void	apply_shadow(t_light *light, t_color *color)
{
	t_color 	shadow;

	shadow = *multiply_on_scalar(color, light->br * -1 * 0.05);
	*color = ft_color_addition(color, &shadow);
}

static int	is_shadowed(t_scene *scene, t_light *light, t_point *point)
{
	t_vector	*light_vector;
	double		distance;
	t_ray		ray;
	t_hit		h;

	light_vector = ft_vec_subtract(light->origin, point);
	distance = ft_vec_len(light_vector);
	ft_vec_normalize(light_vector);
	ray = new_ray(point, light_vector);
	h = new_hit(scene, &ray);
	if (h.object && h.pair.x < distance)
		return (1);
	return (0);
}

t_color	lightning(t_scene *scene, t_comp *computations)
{
	t_light	*light_ptr;
	t_color	color;

	color = ft_color_addition(&(computations->object->color),
							  &(scene->amlight_color));
	light_ptr = scene->light;
	color = ft_color_multiplication(&color, scene->ambient_light);
	if (light_ptr)
	{
		if (!is_shadowed(scene, light_ptr, computations->over_point))
			apply_light(light_ptr, &color, computations);
		else
			apply_shadow(light_ptr, &color);
	}
	return (color);
}
