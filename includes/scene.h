/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:01:28 by kclassie          #+#    #+#             */
/*   Updated: 2022/03/14 14:01:39 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

//содержит указатели на лист всех камер, на лист всех фигур, на лист света
typedef struct	s_scene
{
	t_camera 	*cams;
	t_sphere 	*sphere;
	t_plane 	*plane;
	float 		width;
	float 		height;
}				t_scene;

t_scene	*ft_new_scene(t_camera *cam, t_plane *plane);

#endif
