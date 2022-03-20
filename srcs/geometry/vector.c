/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:52:02 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/18 14:42:31 by dtentaco         ###   ########.fr       */
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
	if (!vec1 && !vec2)
		return (NULL);
	if (!vec1)
		return (ft_new_vec(vec2->x, vec2->y, vec2->z));
	if (!vec2)
		return (ft_new_vec(vec1->x * -1, vec1->y * -1, vec1->z * -1));
	return (ft_new_vec(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z -
			vec2->z));
}

float ft_vec_len(t_vector *vec)
{
	float	len;

	if (!vec)
		return (0);
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

void		ft_vec_mult(t_vector *vec, float num)
{
	vec->x *= num;
	vec->y *= num;
	vec->z *= num;
}

t_vector	*cross_prod3x1(t_vector *vec1, t_vector *vec2)
{
	float	x;
	float	y;
	float	z;
	t_vector	*res;

	x = (vec1->x * vec2->z) - (vec1->z * vec2->y);
	y = (vec1->z * vec2->x) - (vec1->x * vec2->z);
	z = (vec1->x * vec2->y) - (vec1->y * vec2->x);
	res = ft_new_vec(x, y, z);
	return (res);
}
