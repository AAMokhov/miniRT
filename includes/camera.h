/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:59:48 by kclassie          #+#    #+#             */
/*   Updated: 2022/03/14 14:00:11 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

//always == -1 (?why)
typedef struct	s_camera
{
	t_vector	*origin;
	t_vector	*direction;
	float 		fov;
}				t_camera;

t_camera	*ft_new_cam(t_vector *origin, t_vector *direction, float fov);

#endif
