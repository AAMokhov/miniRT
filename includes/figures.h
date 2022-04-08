/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:00:02 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/24 01:14:39 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

# include "minirt.h"
# include "maths.h"

typedef t_pair		(*t_intersection_func)(void *, void *);
typedef t_vector*	(*t_normal_func)(void * , void *);
typedef void		(*t_resize_func)(void *, float);

typedef struct s_plane
{
	t_vector	*centre;
}				t_plane;

typedef struct s_sphere
{
	t_vector	*centre;
	float		radius;
	float		diameter;
	float		squared_radius;
}				t_sphere;

typedef struct s_cylinder
{
	t_vector	*centre;
	float		radius;
	float		height;
	float		squared_radius;
}				t_cylinder;

union			u_figures
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
};

typedef struct s_figures
{
	int					type;
	union u_figures		fig;
	t_color				color;
	t_vector			*normal;
	float				reflective;
	t_intersection_func	intersection_func;
	t_normal_func		normal_func;
	t_resize_func		resize_func;
}					t_figures;

t_vector	*run_normal_at(t_figures *this, void *computations);
t_vector	*normal_at_sphere(void *this, void *computations);
t_vector	*normal_at_plane(void *this, void *computations);
t_vector	*normal_at_cylinder(void *this, void *computations);

void		resize(t_figures *this, float size);
void		resize_sp(void *this, float size);
void		resize_pl(void *this, float size);
void		resize_cy(void *this, float size);

#endif
