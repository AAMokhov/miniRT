/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:33:01 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/27 16:20:16 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	*new_matrix(int size)
{
	t_matrix	*new;
	int			i;
	int			j;

	new = (t_matrix *)enh_malloc(sizeof(t_matrix));
	new->size = size;
	new->a = (float **)enh_malloc(sizeof(float *) * size);
	i = -1;
	while (++i < size)
	{
		new->a[i] = (float *)enh_malloc(sizeof(float *) * size);
		if (!new->a[i])
			return (NULL);
		j = -1;
		while (++j < size)
			new->a[i][j] = 0;
	}
	return (new);
}

/* identity_matrix
 *  | 1 0 0 |
 *  | 0 1 0 |
 *  | 0 0 1 |
 */
t_matrix	*new_identity_matrix(int size)
{
	t_matrix	*new;
	int			i;

	new = new_matrix(size);
	i = -1;
	while (++i < size)
		new->a[i][i] = 1;
	return (new);
}

/*
 * matrix used for POINT translation
 *  | 1 0 0 x |
 *  | 0 1 0 y |
 *  | 0 0 1 z |
 *  | 0 0 0 1 |
 */
t_matrix	*new_translation_matrix(float x, float y, float z)
{
	t_matrix	*new;

	new = new_identity_matrix(4);
	new->a[0][3] = x;
	new->a[1][3] = y;
	new->a[2][3] = z;
	return (new);
}

t_matrix	*new_rotation_matrix(float x_axis, float y_axis, float z_axis)
{
	t_matrix	*new;

	new = new_identity_matrix(4);
	if (x_axis)
	{
		x_axis = radians(x_axis);
		new->a[1][1] = cos(x_axis);
		new->a[1][2] = -sin(x_axis);
		new->a[2][1] = sin(x_axis);
		new->a[2][2] = cos(x_axis);
	}
	if (y_axis)
	{
		y_axis = radians(y_axis);
		new->a[0][0] = cos(y_axis);
		new->a[0][2] = sin(y_axis);
		new->a[2][0] = -sin(y_axis);
		new->a[2][2] = cos(y_axis);
	}
	if (z_axis)
		z_handle(new, z_axis);
	return (new);
}

t_matrix	*new_orientation_matrix(t_vector *left, t_vector *up, t_vector
*forward)
{
	t_matrix	*new;

	new = new_identity_matrix(4);
	new->a[0][0] = left->x;
	new->a[0][1] = left->y;
	new->a[0][2] = left->z;
	new->a[1][0] = up->x;
	new->a[1][1] = up->y;
	new->a[1][2] = up->z;
	new->a[2][0] = -(forward->x);
	new->a[2][1] = -(forward->y);
	new->a[2][2] = -(forward->z);
	return (new);
}
