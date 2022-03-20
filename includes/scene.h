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

typedef struct		s_light
{
	t_vector		*origin;
	float			br;
	int				color;
}					t_light;

//содержит указатели на лист всех камер, на лист всех фигур, на лист света
typedef struct	s_scene
{
	t_camera 	*cams;
	t_sphere 	*sphere;
	t_plane 	*plane;
	t_list		*ls_head_fig;
	t_light		*light;
	int			flg_ambl_light;
	int			amlight_color;
	float		ambient_light;
	float 		width;
	float 		height;
}				t_scene;

#endif
