/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:33:01 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/27 16:20:16 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	z_handle(t_matrix	*new, float z_axis)
{
	z_axis = radians(z_axis);
	new->a[0][0] = cos(z_axis);
	new->a[0][1] = -sin(z_axis);
	new->a[1][0] = sin(z_axis);
	new->a[1][1] = cos(z_axis);
}

t_matrix	*submatrix(t_matrix *matrix, int i, int j)
{
	t_matrix	*new;
	int			n;
	int			m;
	int			skip_i;
	int			skip_j;

	new = new_matrix(matrix->size - 1);
	n = -1;
	skip_i = 0;
	while (++n < new->size)
	{
		skip_j = 0;
		m = -1;
		while (++m < new->size)
		{
			if (n == i)
				skip_i = 1;
			if (m == j)
				skip_j = 1;
			new->a[n][m] = matrix->a[n + skip_i][m + skip_j];
		}
	}
	return (new);
}

void	free_matrix(t_matrix *matrix)
{
	int	i;

	i = -1;
	if (!matrix)
		return ;
	while (++i < matrix->size)
	{
		free(matrix->a[i]);
		matrix->a[i] = NULL;
	}
	free(matrix->a);
	matrix->a = NULL;
	free(matrix);
	matrix = NULL;
}

float	minor(t_matrix *matrix, int i, int j)
{
	float		det;
	t_matrix	*sub;

	sub = submatrix(matrix, i, j);
	det = determinant(sub);
	free_matrix(sub);
	return (det);
}
