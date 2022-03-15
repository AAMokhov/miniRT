/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:59:00 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/16 00:38:11 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include "lib_vector.h"
# include "utils.h"
# include "sphere.h"
# include "camera.h"
# include "scene.h"
# include "view_plane.h"
# include "figures.h"
# include "sphere_intersection.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# ifdef MACOS
#  define OS_NAME 1
# endif

# define BUFSIZE 32

# define REFLECTION_LIMIT 3

# define SP 0 // sphere
# define PL 1 // plane
# define CY 2 // cylinder

# define EPSILON 0.00001

typedef struct		s_minilibx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_minilibx;

void ft_ray_tracing(void *mlx, void *window, t_scene *scene);

/*
**			 	Parsing functions
*/

void		parse_scene(t_scene *data, char **av);

void		parse_ambient_light(t_scene *data, char **str);
void		parse_light(t_list **is_head_fig, char **str);
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
int			parse_color(char **str);
void		check_iscomma(char **str);
t_vector	*parse_vec(char **str);
#endif
