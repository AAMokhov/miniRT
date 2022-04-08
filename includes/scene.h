/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 00:15:20 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/24 01:28:54 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "matrix.h"
# include "tuple.h"

typedef struct s_camera
{
	t_point		*origin;
	t_vector	*direction;
	float		fov;
}				t_camera;

typedef struct s_light
{
	t_vector		*origin;
	float			br;
	t_color			color;
}					t_light;

typedef struct s_image
{
	void		*img_ptr;
	char		*img_adr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			h;
	int			w;
}					t_image;

typedef struct s_vplane
{
	float		width;
	float		height;
	float		x_pixel;
	float		y_pixel;
	float		rotation_x;
	float		rotation_y;
	t_matrix	*transform;
	t_matrix	*rotate;
}				t_vplane;

typedef struct s_scene_attr
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_camera	*cams;
	t_list		*ls_head_fig;
	t_light		*light;
	t_image		canvas;
	t_vplane	*vplane;
	int			flg_ambl_light;
	t_color		amlight_color;
	float		ambient_light;
	float		width;
	float		height;
}				t_scene;

int		ft_get_view_plane(t_scene *scene);

#endif
