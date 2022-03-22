/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:56:32 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/22 15:41:10 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"
# include "tuple.h"
# include "ray.h"

typedef struct s_hit			t_hit;
typedef struct s_computations	t_comp;

struct	s_hit
{
	t_object	*object;
	t_pair		pair;
};

struct s_computations
{
	t_ray		*ray;
	t_object	*object;
	float		t1;
	float		t2;
	t_point		point;
	t_point		over_point;
	t_vector	eye_v;
	t_vector	reflect_v;
	t_vector 	normal;
};

int		ft_rgb2int(t_color color);
t_color	new_color(t_scene *scene, t_ray *ray, int recursion_depth);

#endif
