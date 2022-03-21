/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:48:17 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/18 14:48:27 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void ft_ray_tracing(t_minilibx *mlx, t_scene *scene)
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
		y_ray = y_angle * mlx->vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while (x_angle < scene->width / 2)
		{
			x_ray = x_angle * mlx->vplane->x_pixel;
			ray = ft_new_vec(x_ray, y_ray, -1);
			color = ft_pixel_color(scene, ray);
			ft_mlx_pixel_put(scene->cams, mlx_x, mlx_y, color);
			free (ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}

t_vplane	*ft_get_view_plane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float 		aspect_ratio; //масштабирование

	(void)fov;
	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		ft_error_exit(-1);
	aspect_ratio = width * pow(height, (-1));
	vplane->width = (tan((float)fov / 2 * (M_PI / 180))) * 2;
	vplane->height = vplane->width * pow(aspect_ratio, -1);
	vplane->x_pixel = vplane->width * pow(width, -1);
	vplane->y_pixel = vplane->height * pow(height, -1);
	return (vplane);
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
			if (ft_sph_intersect(scene->cams, ray, &ls_ptr->fig.sp))
				return (ls_ptr->color);// TMP
		}
		if (ls_ptr->type == PL)
		{
			if (ft_pl_intersect(scene->cams, ray, ls_ptr))
				return (ls_ptr->color);// TMP
		}
		ls_head = ls_head->next;
	}
	return (color);
}
