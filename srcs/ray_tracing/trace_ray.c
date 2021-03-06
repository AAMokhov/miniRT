/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:48:17 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/27 21:05:50 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	new_image(t_scene *scene)
{
	scene->canvas.img_ptr = mlx_new_image(scene->mlx_ptr,
			scene->width, scene->height);
	if (!scene->canvas.img_ptr)
		return (ERROR);
	scene->canvas.img_adr = mlx_get_data_addr(scene->canvas.img_ptr, \
											&scene->canvas.bits_per_pixel, \
											&scene->canvas.line_length, \
											&scene->canvas.endian);
	if (!scene->canvas.img_adr)
		return (ERROR);
	ft_ray_tracing(scene);
	mlx_put_image_to_window(scene->mlx_ptr, scene->win_ptr,
		scene->canvas.img_ptr, 0, 0);
	mlx_destroy_image(scene->mlx_ptr, scene->canvas.img_ptr);
	return (SUCCESS);
}

t_ray	trace_ray(t_point *origin, int x, int y, t_vplane *view)
{
	t_ray		ray;
	t_tuple		*position;

	position = new_tuple(x * view->x_pixel,
			y * view->y_pixel, -1, VECTOR);
	position = multiply_matrix_tuple(view->transform, position);
	position = multiply_matrix_tuple(view->rotate, position);
	ft_vec_normalize(position);
	ray = new_ray(origin, position);
	return (ray);
}

void	ft_ray_tracing(t_scene *scene)
{
	t_ray		ray;
	int			x;
	int			y;
	int			half_w;
	int			half_h;

	half_w = scene->width / 2;
	half_h = scene->height / 2;
	y = half_h + 1;
	while (--y > -(half_h))
	{
		x = -(half_w) - 1;
		while (++x < half_w)
		{
			ray = trace_ray(scene->cams->origin, x, y, scene->vplane);
			ft_mlx_pixel_put(&(scene->canvas), \
					(int)ft_module(x + half_w), \
					(int)ft_module(y - half_h), \
					ft_rgb2int(new_color(scene, &ray, 3)));
		}
	}
}
