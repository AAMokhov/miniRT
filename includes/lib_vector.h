/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_vector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:13:11 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/18 14:06:35 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_VECTOR_H
# define LIB_VECTOR_H

# include <math.h>

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

t_vector	*ft_new_vec(float x, float y, float z);
t_vector	*ft_vec_subtraction(t_vector *vec1, t_vector *vec2);
float		ft_vec_len(t_vector *vec);
void		ft_vec_normalize(t_vector *vec);
float		ft_vec_dotprod(t_vector *vec1, t_vector *vec2);
void		ft_vec_mult(t_vector *vec, float num);
t_vector	*cross_prod3x1(t_vector *vec1, t_vector *vec2);

#endif
