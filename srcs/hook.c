/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:56:21 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/28 19:32:42 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_program(void *param)
{
	param = (void *)param;
	exit(EXIT_SUCCESS);
	return (1);
}

int	key_hook(int keycode, t_scene *scene)
{
	printf("WAS KEY %d\n", keycode);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
		exit(0);
	}
	else if (keycode == 13)
		scene->cams->origin->y += 0.2;
	else if (keycode == 1)
		scene->cams->origin->y -= 0.2;
	else if (keycode == 0)
		scene->cams->origin->x -= 0.2;
	else if (keycode == 2)
		scene->cams->origin->x += 0.2;
	if (keycode == 123)
		scene->vplane->rotation_y += 30;
	else if (keycode == 124)
		scene->vplane->rotation_y -= 30;
	else if (keycode == UP_KEY)
		scene->vplane->rotation_x += 30;
	else if (keycode == DOWN_KEY)
		scene->vplane->rotation_x -= 30;
	free_matrix(scene->vplane->rotate);
	scene->vplane->rotate = new_rotation_matrix(scene->vplane->rotation_x,
											scene->vplane->rotation_y,
											0);
	return (new_image(scene));
}
