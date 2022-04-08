/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:56:21 by dtentaco          #+#    #+#             */
/*   Updated: 2022/04/08 20:01:46 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_program(void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (scene->win_ptr)
		mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_scene *scene)
{
	if (keycode == ESC_KEY)
		close_program(scene);
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
			scene->vplane->rotation_y, 0);
	return (new_image(scene));
}

static void	move_camera(t_scene *scene, t_tuple translation, float speed)
{
	t_vector	*direction;

	direction = new_tuple(scene->cams->direction->x,
			scene->cams->direction->y, scene->cams->direction->z, VECTOR);
	direction->x *= translation.x;
	direction->y *= translation.y;
	direction->z *= translation.z;
	direction = multiply_on_scalar(direction, speed);
	scene->cams->origin = ft_vec_add(scene->cams->origin, direction);
}

int	mouse_hook(int button, int x, int y, t_scene *scene)
{
	t_ray		ray;
	t_hit		hit;

	if (button == 4)
		move_camera(scene, (t_tuple){-1, -1, 1, POINT}, 0.5);
	if (button == 5)
		move_camera(scene, (t_tuple){-1, -1, 1, POINT}, -0.5);
	if (button == 1 || button == 3)
	{
		ray = trace_ray(scene->cams->origin, x - (scene->width / 2),
				(y - (scene->height / 2)) * -1, scene->vplane);
		hit = new_hit(scene, &ray);
		if (hit.object)
		{
			if (button == 3)
				resize(hit.object, 1.15);
			else
				resize(hit.object, 0.85);
		}
	}
	return (new_image(scene));
}
