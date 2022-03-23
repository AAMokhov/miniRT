/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:39:57 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/23 23:58:49 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_get_view_plane(t_scene *scene)
{
	t_vplane	*vplane;
	float 		aspect_ratio; //масштабирование

	vplane = (t_vplane *)enh_malloc(sizeof(t_vplane));
	aspect_ratio = scene->width * pow(scene->height, (-1));

	vplane->width = (tan(scene->cams->fov / 2 * (M_PI / 180))) * 2;
	vplane->height = vplane->width * pow(aspect_ratio, -1);

	vplane->x_pixel = vplane->width * pow(scene->width, -1);
	vplane->y_pixel = vplane->height * pow(scene->height, -1);

	vplane->rotation_x = 0;
	vplane->rotation_y = 0;

	// free_matrix(vplane->rotate);
	// vplane->rotate = new_identity_matrix(4);
	// free_matrix(vplane->transform);
	// vplane->transform = transform_view(scene->cams->origin,
	// 									  scene->cams->direction,
	// 									   (t_vector){0, 1, 0, VECTOR});
	scene->vplane = vplane;
	return (SUCCESS);
}

t_matrix	*transform_view(t_point *from, t_vector *forward, t_vector up)
{
	t_vector *left;
	t_vector *true_up;
	t_matrix *orientation;
	t_matrix *translation;
	t_matrix *transform;
	t_matrix *tmp;

	if (compare_tuples(forward, &(t_tuple){0, 1, 0, VECTOR}))
		up = (t_vector){0, 0, -1, VECTOR};
	else if (compare_tuples(forward, &(t_tuple){0, -1, 0, VECTOR}))
		up = (t_vector){0, 0, 1, VECTOR};
	left = cross_prod3x1(forward, &up);
	true_up = cross_prod3x1(left, forward);
	orientation = new_orientation_matrix(left, true_up, forward);
	translation = new_translation_matrix((from->x), (from->y),(from->z));
	if (!orientation || !translation)
		return (NULL);
	transform = multiply_matrix(translation, orientation);
	if (!transform)
		return (NULL);
	free_matrix(orientation);
	free_matrix(translation);

	tmp = transform;
	transform = inverse(transform);
	if (!transform)
		return (NULL);
	free_matrix(tmp);

	return (transform);
}
