/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:04:12 by kclassie          #+#    #+#             */
/*   Updated: 2022/03/14 14:04:15 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector *ft_new_vec(float x, float y, float z)
{
	t_vector	*vec;

	vec = malloc(sizeof(t_vector));
	if (!vec)
		ft_error_exit(-1);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vector *ft_vec_subtraction(t_vector *vec1, t_vector *vec2)
{
	t_vector	*result;

	result = ft_new_vec(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z -
			vec2->z);
	return (result);
}

float ft_vec_len(t_vector *vec)
{
	float	len;

	len = sqrtf(pow(vec->x, 2.0) + pow(vec->y, 2.0) + pow(vec->z, 2.0));
	return (len);
}

void	ft_vec_normalize(t_vector *vec)
{
	float	len;

	len = ft_vec_len(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

float	ft_vec_dotprod(t_vector *vec1, t_vector *vec2)
{
	float	result;

	result = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (result);
}

//добавить функцию умножения вектора на какое-то число
// ft_vec_miltiply(t_vector *vec, float multiplier)
