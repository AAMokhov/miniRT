/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:47:54 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/23 11:06:34 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <float.h>

typedef struct s_pair	t_pair;

struct s_pair
{
	float	x;
	float	y;
};

float 	radians(float degrees);
float	ft_max_module(float a, float b);
float	ft_min_module(float a, float b);
float	ft_max(float a, float b);
float	ft_min(float a, float b);
float	ft_pow(float num, int n);
float	ft_module(float a);
int		ft_equal(float a, float b);
t_pair	ft_quadratic_roots(float a, float b, float c);

#endif
