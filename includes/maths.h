/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:47:54 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/23 11:06:34 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <float.h>
# include "tuple.h"

typedef struct s_pair	t_pair;

struct s_pair
{
	float	x;
	float	y;
};

// math

float		radians(float degrees);
float		ft_module(float a);
int			ft_equal(float a, float b);
t_pair		ft_quadratic_roots(float a, float b, float c);

// vector

t_tuple		*ft_vec_add(const t_tuple *tuple1, const t_tuple *tuple2);
t_vector	*ft_vec_subtract(t_vector *vec1, t_vector *vec2);
float		ft_vec_len(t_vector *vec);
void		ft_vec_normalize(t_vector *vec);
float		ft_vec_dotprod(t_vector *vec1, t_vector *vec2);
t_vector	*cross_prod3x1(t_vector *vec1, t_vector *vec2);

#endif
