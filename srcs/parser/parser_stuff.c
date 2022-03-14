/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:51:08 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/15 00:27:24 by dtentaco         ###   ########.fr       */
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
	t_vector	*origin;
	t_vector	*dir;
	float 		fov;

	origin = parse_vec(str);
	dir = parse_vec(str);
	ft_vec_normalize(dir);
	fov = ft_atoi_ptr(str);
	check_in_range(fov, 0, 180, "camera");
	data->cams = ft_new_cam(origin, dir, fov);
}
