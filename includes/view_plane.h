/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_plane.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:02:57 by kclassie          #+#    #+#             */
/*   Updated: 2022/03/14 14:03:02 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_PLANE_H
# define VIEW_PLANE_H

typedef struct	s_vplane
{
	float		width;
	float		height;
	float 		x_pixel; //пиксель окна просмотра
	float 		y_pixel;
}				t_vplane;

t_vplane	*ft_get_view_plane(float width, float height, float fov);
#endif
