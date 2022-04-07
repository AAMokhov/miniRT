/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:59:00 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/29 23:44:34 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/minilibx_opengl_20191021/mlx.h"
# include "../lib/libft/includes/libft.h"
# include "scene.h"
# include "figures.h"
# include "intersection.h"
# include "ggl_mlx_define.h"
# include "matrix.h"
# include "render.h"
# include "ray.h"
# include "tuple.h"
# include "maths.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# ifdef MACOS
# endif

# define BUFSIZE 32

# define WIN_HEIGHT	450
# define WIN_WIDTH	600

# define SUCCESS	1
# define ERROR		0

# define SP 0 // sphere
# define PL 1 // plane
# define CY 2 // cylinder

# define EPSILON 0.00001

t_camera	*ft_new_cam(t_vector *origin, t_vector *direction, float fov);
int			new_image(t_scene *scene);
void		ft_ray_tracing(t_scene *scene);
t_ray		trace_ray(t_point *origin, int x, int y, t_vplane *view);

/*
**			 	Parsing functions
*/

void		parse_scene(t_scene *data, char **av);
void		parse_ambient_light(t_scene *data, char **str);
void		parse_light(t_light **cs_light, char **str);
void		parse_camera(t_scene *data, char **str);
void		parse_cylinder(t_list **is_head_fig, char **str);
void		parse_sphere(t_list **is_head_fig, char **str);
void		parse_plane(t_list **is_head_fig, char **str);

/*
**				Parsing help functions
*/

char		*readfile(char *str, int fd);
void		get_next(char **str);
float		ft_atof(char **str);
int			ft_atoi_ptr(char **str);
void		check_in_range(float nb, float min, float max, char *str_obj);
t_color		parse_color(char **str);
void		check_iscomma(char **str);
t_vector	*parse_vec(char **str);

/*
**				Output for user
*/

void		print_obj(t_scene *data);
void		print_staff(t_scene *data);
void		print_sphere(t_figures *ls_ptr, int i);
void		print_plane(t_figures *ls_ptr, int i);
void		print_cylinder(t_figures *ls_ptr, int i);
void		print_extra(t_figures *ls_ptr);

/*
**				Minilibx functions
*/

void		init_scene(t_scene *data);
int			init_mlx(t_scene *scene);
void		graphic_loop(t_scene data);
int			key_hook(int keycode, t_scene *data);
int			mouse_hook(int button, int x, int y, t_scene *scene);
int			close_program(void *param);
void		ft_mlx_pixel_put(t_image *canvas, int x, int y, int color);

/*
**				Utils
*/

void		ft_error_exit(int code);
void		*enh_malloc(unsigned int size);
void		scene_error(char *message);
void		fatal(char *message);

#endif
