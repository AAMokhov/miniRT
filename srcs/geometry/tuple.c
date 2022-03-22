/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 00:19:02 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/22 13:52:22 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	new_tuple(float x, float y, float z, float type)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = type;
	return (new);
}

t_tuple	add(const t_tuple *tuple1, const t_tuple *tuple2)
{
	t_tuple	t3;

	t3 = new_tuple(tuple1->x + tuple2->x,
			   tuple1->y + tuple2->y,
			   tuple1->z + tuple2->z,
			   tuple1->w + tuple2->w);
	return (t3);
}

float	module_v(const t_point* vector)
{
	return (sqrt((vector->x * vector->x) +
				 (vector->y * vector->y) +
				 (vector->z * vector->z) +
				 (vector->w * vector->w)));
}

void	normalize(t_point *vector)
{
	float	module;

	module = module_v(vector);
	if (!module)
		return ;
	vector->x /= module;
	vector->y /= module;
	vector->z /= module;
	vector->w /= module;
}

float	dot(const t_point* vector1, const t_point* vector2)
{
	return (vector1->x * vector2->x +
			vector1->y * vector2->y +
			vector1->z * vector2->z +
			vector1->w * vector2->w);
}

int		compare_tuples(const t_tuple *tuple1, const t_tuple *tuple2)
{
	return (ft_equal(tuple1->x, tuple2->x) &&\
			ft_equal(tuple1->y, tuple2->y) &&\
			ft_equal(tuple1->z, tuple2->z) &&\
			ft_equal(tuple1->w, tuple2->w));
}

t_tuple	subtract(const t_tuple *tuple1, const t_tuple *tuple2)
{
	t_tuple t3;

	t3 = new_tuple(tuple1->x - tuple2->x,
			   tuple1->y - tuple2->y,
			   tuple1->z - tuple2->z,
			   tuple1->w - tuple2->w);
	return (t3);
}

void	scale(t_tuple *tuple, float scalar)
{
	tuple->x *= scalar;
	tuple->y *= scalar;
	tuple->z *= scalar;
}

t_tuple   multiply_on_scalar(const t_tuple *tuple1, float scalar)
{
	t_tuple	tuple2;

	tuple2 = new_tuple(tuple1->x * scalar,
				   tuple1->y * scalar,
				   tuple1->z * scalar,
				   tuple1->w);
	return (tuple2);
}

