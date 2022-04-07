/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:52:02 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/27 16:45:57 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	*ft_vec_add(const t_tuple *tuple1, const t_tuple *tuple2)
{
	t_tuple	*t3;

	t3 = new_tuple(tuple1->x + tuple2->x, tuple1->y + tuple2->y,
			tuple1->z + tuple2->z, tuple1->w + tuple2->w);
	return (t3);
}

t_vector	*ft_vec_subtract(t_vector *vec1, t_vector *vec2)
{
	if (!vec1 && !vec2)
		return (NULL);
	if (!vec1)
		return (new_tuple(vec2->x, vec2->y, vec2->z, vec2->w));
	if (!vec2)
		return (new_tuple(vec1->x * -1, vec1->y * -1, vec1->z * -1,
				vec1->w * -1));
	return (new_tuple(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z,
			vec1->w - vec2->w));
}

float	ft_vec_len(t_vector *vec)
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
	if (!len)
		return ;
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
	vec->w /= len;
}

float	ft_vec_dotprod(t_vector *vec1, t_vector *vec2)
{
	float	result;

	result = (vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z)
		+ (vec1->w * vec2->w);
	return (result);
}
