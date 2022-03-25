/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 00:15:20 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/24 01:28:54 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
#define TUPLE_H

# define VECTOR	0
# define POINT	1
# define COLOR	3.3

typedef struct s_base_tuple	t_tuple;

typedef t_tuple				t_vector;
typedef t_tuple				t_point;
typedef t_tuple				t_color;

struct	s_base_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
};

t_tuple		*new_tuple(float x, float y, float z, float type);
t_tuple		*multiply_on_scalar(const t_tuple *tuple1, float scalar);
int			compare_tuples(const t_tuple *tuple1, const t_tuple *tuple2);
t_vector	*reflect(t_vector* ray, t_vector* normal);
#endif
