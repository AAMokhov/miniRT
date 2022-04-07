/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:56:32 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/23 21:57:55 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"
# include "tuple.h"
# include "ray.h"
# include "maths.h"

typedef struct s_hit			t_hit;
typedef struct s_computations	t_comp;

struct	s_hit
{
	t_figures	*object;
	t_pair		pair;
};

struct s_computations
{
	t_ray		*ray;
	t_figures	*object;
	float		t1;
	float		t2;
	t_point		*point;
	t_point		*over_point;
	t_vector	*eye_v;
	t_vector	*reflect_v;
	t_vector	*normal;
};

int		ft_rgb2int(t_color color);
t_color	new_color(t_scene *scene, t_ray *ray, int recursion_depth);
t_color	ft_color_multiplication(t_color *color_1, float scalar);
t_color	ft_color_addition(t_color *color_1, t_color *color_2);
t_hit	new_hit(t_scene *scene, t_ray *ray);
void	prepare_computations(t_comp *computations, t_scene *scene, t_ray *ray);
t_color	lightning(t_scene *scene, t_comp *computations);

#endif
