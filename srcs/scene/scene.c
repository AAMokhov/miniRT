/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:05:46 by kclassie          #+#    #+#             */
/*   Updated: 2022/03/14 14:05:51 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*ft_new_scene(t_camera *cam, t_plane *plane)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		ft_error_exit(-1);
	scene->cams = cam;
	scene->plane = plane;
	scene->width = 0;
	scene->height = 0;
	return (scene);
}

