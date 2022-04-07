/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:33:01 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/27 16:20:16 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	transpose(t_matrix **matrix)
{
	float	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < (*matrix)->size)
	{
		j = i;
		while (j < (*matrix)->size)
		{
			tmp = (*matrix)->a[i][j];
			(*matrix)->a[i][j] = (*matrix)->a[j][i];
			(*matrix)->a[j][i] = tmp;
			j++;
		}
		i++;
	}
}

float	determinant(t_matrix *matrix)
{
	float	det;
	int		j;

	if (matrix->size == 2)
		return ((matrix->a[0][0] * matrix->a[1][1]) -
				(matrix->a[0][1] * matrix->a[1][0]));
	else
	{
		det = 0;
		j = -1;
		while (++j < matrix->size)
			det += matrix->a[0][j] * minor(matrix, 0, j) * pow(-1, 0 + j);
	}
	return (det);
}

t_matrix	*inverse(t_matrix *matrix)
{
	t_matrix	*new;
	float		det;
	int			i;
	int			j;

	det = determinant(matrix);
	if (det == 0)
		return (NULL);
	new = new_matrix(matrix->size);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < new->size)
	{
		j = -1;
		while (++j < new->size)
			new->a[i][j] = minor(matrix, i, j) * pow(-1, i + j) / det;
	}
	transpose(&new);
	return (new);
}

t_matrix	*multiply_matrix(t_matrix *matrix1, t_matrix *matrix2)
{
	t_matrix	*result;
	float		element;
	int			i;
	int			j;
	int			k;

	result = new_matrix(matrix1->size);
	i = -1;
	while (++i < matrix1->size)
	{
		j = -1;
		while (++j < matrix1->size)
		{
			element = 0;
			k = -1;
			while (++k < matrix1->size)
				element += matrix1->a[i][k] * matrix2->a[k][j];
			result->a[i][j] = element;
		}
	}
	return (result);
}

t_tuple	*multiply_matrix_tuple(t_matrix *matrix, t_tuple *tuple)
{
	t_tuple	*result;
	float	array[4];
	int		i;

	result = new_tuple(0, 0, 0, 0);
	i = -1;
	while (++i < matrix->size)
	{
		array[i] = (matrix->a[i][0] * tuple->x) + (matrix->a[i][1] * tuple->y)
			+ (matrix->a[i][2] * tuple->z) + (matrix->a[i][3] * tuple->w);
	}
	result->x = array[0];
	result->y = array[1];
	result->z = array[2];
	result->w = array[3];
	return (result);
}
