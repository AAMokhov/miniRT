/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:01:07 by kclassie          #+#    #+#             */
/*   Updated: 2022/03/14 14:01:14 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
#define PLANE_H

typedef struct			s_plane
{
	t_vector			*centre; //x, y, z
	t_vector			*orientation; //3d normalized orientation vector. In range [-1,1] for each x,y,z axis:0.0,0.0,1.0
	t_color				*color;
	struct	s_plane		*next;
}						t_plane;

t_plane	*ft_new_plane(t_vector *centre, t_vector *orientation, t_color *color);

#endif
