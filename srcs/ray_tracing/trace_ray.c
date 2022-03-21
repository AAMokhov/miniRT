/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:48:17 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/21 17:39:04 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	new_image(t_scene *scene)
{
	scene->canvas.img_ptr = mlx_new_image(scene->mlx_ptr, scene->width, scene->height);
	if (!scene->canvas.img_ptr)
		return (ERROR);
	scene->canvas.img_adr = mlx_get_data_addr(scene->canvas.img_ptr, \
											&scene->canvas.bits_per_pixel, \
											&scene->canvas.line_length, \
											&scene->canvas.endian);

	if (!scene->canvas.img_adr)
		return (ERROR);

	ft_ray_tracing(scene);
	mlx_put_image_to_window(scene->mlx_ptr, scene->win_ptr, scene->canvas.img_ptr, 0, 0);
	return (SUCCESS);
}

void ft_ray_tracing(t_scene *scene)
{
	int			mlx_x;
	int			mlx_y; //for mlx_pixel_put - заменить на mlx_image
	float		x_angle;
	float 		y_angle;
	int 		color;
	float 		y_ray; //  координаты луча
	float 		x_ray;
	t_vector	*ray;

	mlx_y = 0;
	y_angle = (scene->height / 2);
	while (y_angle > (scene->height / 2) * (-1))
	{
		y_ray = y_angle * scene->vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while (x_angle < scene->width / 2)
		{
			x_ray = x_angle * scene->vplane->x_pixel;
			ray = ft_new_vec(x_ray, y_ray, -1);
			color = ft_pixel_color(scene, ray);
			ft_mlx_pixel_put(&scene->canvas, mlx_x, mlx_y, color);
			free (ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}

int		ft_get_view_plane(t_scene *scene)
{
	t_vplane	*vplane;
	float 		aspect_ratio; //масштабирование

	vplane = (t_vplane *)enh_malloc(sizeof(t_vplane));
	aspect_ratio = scene->width * pow(scene->height, (-1));

	vplane->width = (tan(scene->cams->fov / 2 * (M_PI / 180))) * 2;
	vplane->height = vplane->width * pow(aspect_ratio, -1);

	vplane->x_pixel = vplane->width * pow(scene->width, -1);
	vplane->y_pixel = vplane->height * pow(scene->height, -1);

	vplane->rotation_x = 0;
	vplane->rotation_y = 0;

	vplane->transform = NULL;
	vplane->rotate = NULL;
	//something wirh transform matrix
	scene->vplane = vplane;
	return (SUCCESS);
}

int	ft_pixel_color(t_scene *scene, t_vector *ray)
{
	int			color_from_light;
	int			color;
	t_figures	*ls_ptr;
	t_list		*ls_head;

	color_from_light = 0;
	color = 0;
	ls_head = scene->ls_head_fig;
	ft_vec_normalize(ray);
	while (ls_head)
	{
		ls_ptr = (t_figures *)(ls_head->content);
		if (ls_ptr->type == SP)
		{
		//функция пересечения со сферой
			if (ft_sph_intersect(scene->cams, ray, &ls_ptr->fig.sp))
				return (ls_ptr->color);// TMP
		}
		ls_head = ls_head->next;
	}
	return (color);
}
