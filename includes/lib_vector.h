/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_vector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:13:11 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/22 20:19:23 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_VECTOR_H
# define LIB_VECTOR_H

# include <math.h>
# include "tuple.h"

// t_vector	*ft_new_vec(float x, float y, float z);
t_tuple		*ft_vec_add(const t_tuple *tuple1, const t_tuple *tuple2);
t_vector	*ft_vec_subtract(t_vector *vec1, t_vector *vec2);
float		ft_vec_len(t_vector *vec);
void		ft_vec_normalize(t_vector *vec);
float		ft_vec_dotprod(t_vector *vec1, t_vector *vec2);
void		ft_vec_mult(t_vector *vec, float num);
t_vector	*cross_prod3x1(t_vector *vec1, t_vector *vec2);
#endif
