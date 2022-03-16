/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:00:02 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/16 14:51:26 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

# include "minirt.h"

// typedef struct	s_sphere
// {
// 	t_vector	c;
// 	float		r;
// 	// int		inside;
// }				t_sphere;

typedef struct	s_plane
{
	t_vector	*p;
	float		width;
	float		height;
	float 		x_pixel; //пиксель окна просмотра
	float 		y_pixel;
}				t_plane;

typedef struct	s_cylinder
{
	t_vector	*centre;
	float		radius;
	float		height;
	float		dist1;
	float		dist2;
}				t_cylinder;

union			u_figures
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
};

typedef struct		s_figures
{
	int					type;
	union u_figures		fig;
	int					color;
	t_vector			*normal;
}					t_figures;

#endif
