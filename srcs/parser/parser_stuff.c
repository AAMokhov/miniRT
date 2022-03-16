/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:51:08 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/16 14:59:56 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_ambient_light(t_scene *data, char **str)
{
	if (data->flg_ambl_light > 0)
		scene_error(
			"Ambient lightning (A) can only be declared once in the scene\n");
	else
		data->flg_ambl_light = 1;
	get_next(str);
	data->ambient_light = ft_atof(str);
	check_in_range(data->ambient_light, 0, 1, "ambient lightning");
	data->amlight_color = parse_color(str);
}

void		parse_camera(t_scene *data, char **str)
{
	t_camera	new_cam;

	if (data->cams != NULL)
	{
		scene_error(
			"Camera(C) can only be declared once in the scene\n");
	}
	get_next(str);
	new_cam.origin = parse_vec(str);
	new_cam.direction = parse_vec(str);
	ft_vec_normalize(new_cam.direction);
	new_cam.fov = ft_atoi_ptr(str);
	check_in_range(new_cam.fov, 0, 180, "camera");
	data->cams = ft_new_cam(new_cam.origin, new_cam.direction, new_cam.fov);
}

void		parse_light(t_light *cs_light, char **str)
{
	t_light	*new_light;

	new_light = enh_malloc(sizeof(t_light));
	get_next(str);
	new_light->origin = parse_vec(str);
	new_light->br = ft_atof(str);
	check_in_range(new_light->br, 0, 1, "light");
	new_light->color = parse_color(str);
	cs_light = new_light;
}
