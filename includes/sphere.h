/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:01:56 by kclassie          #+#    #+#             */
/*   Updated: 2022/03/14 14:02:02 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

typedef struct			s_sphere
{
	t_vector			*centre;
	float				radius;
	t_color				*color;
	struct	s_sphere	*next;
}						t_sphere;

t_sphere	*ft_new_sphere(t_vector *centre, float	radius, t_color	*color);

#endif
