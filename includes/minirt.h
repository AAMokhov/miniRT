/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:59:00 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/11 23:15:07 by dtentaco         ###   ########.fr       */
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
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define REFLECTION_LIMIT 3

# define SP 0
# define PL 1
# define SQ 2
# define TR 3
# define CY 4
# define CU 5
# define PY 6

# define EPSILON 0.00001

typedef struct		s_minilibx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_minilibx;

void ft_ray_tracing(void *mlx, void *window, t_scene *scene);

#endif
