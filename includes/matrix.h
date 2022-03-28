/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:23:49 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/23 23:54:57 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
#define MATRIX_H

typedef struct s_matrix	t_matrix;

struct	s_matrix
{
	float	**a;
	int		size;
	float	det;
};

t_matrix	*transform_view(t_point *from, t_vector *forward, t_vector up);

t_matrix*	new_matrix(int size);
t_matrix*	new_identity_matrix(int size);
t_matrix*	new_translation_matrix(float x, float y, float z);
t_matrix*	new_scaling_matrix(float x, float y, float z);
t_matrix*	new_rotation_matrix(float x_axis, float y_axis, float z_axis);
t_matrix*	new_orientation_matrix(t_vector *left, t_vector *up, t_vector *forward);
t_matrix*	submatrix(t_matrix *matrix, int i, int j);
t_matrix*	inverse(t_matrix *matrix);
t_matrix*	multiply_matrix(t_matrix *matrix1, t_matrix *matrix2);
t_tuple		*multiply_matrix_tuple(t_matrix *matrix, t_tuple* tuple);
float 		determinant(t_matrix *matrix);
void		transpose(t_matrix **matrix);
float 		minor(t_matrix *matrix, int i, int j);
void		free_matrix(t_matrix *matrix);

#endif
