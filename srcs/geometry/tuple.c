/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 00:19:02 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/27 16:46:01 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	*new_tuple(float x, float y, float z, float type)
{
	t_tuple	*new;

	new = (t_tuple *)enh_malloc(sizeof(t_tuple));
	new->x = x;
	new->y = y;
	new->z = z;
	new->w = type;
	return (new);
}

int		compare_tuples(const t_tuple *tuple1, const t_tuple *tuple2)
{
	return (ft_equal(tuple1->x, tuple2->x) &&\
			ft_equal(tuple1->y, tuple2->y) &&\
			ft_equal(tuple1->z, tuple2->z) &&\
			ft_equal(tuple1->w, tuple2->w));
}

t_tuple	*multiply_on_scalar(const t_tuple *tuple1, float scalar)
{
	t_tuple	*tuple2;

	tuple2 = new_tuple(tuple1->x * scalar,
				   tuple1->y * scalar,
				   tuple1->z * scalar,
				   tuple1->w);
	return (tuple2);
}

// вычисление отраженного вектора
t_vector	*reflect(t_vector* ray, t_vector* normal)
{
	t_vector *reflected;
	t_vector *mult;

	mult = multiply_on_scalar(normal, 2 * ft_vec_dotprod(ray, normal));
	reflected = ft_vec_subtract(ray, mult);
	return (reflected);
}
