/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:53:04 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/22 15:41:24 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_rgb2int(t_color color)
{
	return (((int)color.x << 16 | (int)color.y << 8 | (int)color.z));
}

t_color	new_color(t_scene *scene, t_ray *ray, int recursion_depth)
{
	t_comp	computations;
	t_color	color;
	t_color	reflected_color;
	t_ray	reflected_ray;


	return (color);
}
