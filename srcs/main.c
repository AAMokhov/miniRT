/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:03:39 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/18 01:31:42 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minilibx	mlx;
	t_scene		data;

	if (argc != 2)
		ft_error_exit(-2);
	parse_scene(&data, argv);
	init_mlx(&mlx, &data);
	ft_ray_tracing(&mlx, &data);
	graphic_loop(mlx, data);
	return(0);
}

void	init_mlx(t_minilibx *mlx, t_scene *data)
{
	mlx->mlx_ptr = mlx_init();
	data->width = 800;
	data->height = 600;
	mlx->vplane = ft_get_view_plane(data->width, data->height, data->cams->fov); //создаем окно прсомотра

	data->cams->img_ptr = mlx_new_image(mlx->mlx_ptr, data->width, data->height); // какой нужно размер?
	data->cams->img_adr = mlx_get_data_addr(data->cams->img_ptr, \
			&data->cams->bits_per_pixel, &data->cams->line_length, &data->cams->endian);
}

void		graphic_loop(t_minilibx mlx, t_scene data)
{
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, data.width, data.height,
															"miniRT");
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, data.cams->img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_program, 0);
	mlx_loop(mlx.mlx_ptr);
}

	//TEST
// 	mlx.mlx_ptr = mlx_init();
// 	t_vector  *sphere_centre = ft_new_vec(3, 2, -32);
// 	// t_sphere 	*sphere = ft_new_sphere(sphere_centre, 12/2);
// 	t_vector 	*cam_orign = ft_new_vec(0, 0, 0); //нужна функция для преобразования любых координат
// 	t_vector 	*cam_direction = ft_new_vec(0, 0, -1); //||-||-||
// 	t_camera 	*cam = ft_new_cam(cam_orign, cam_direction, 70);
// 	t_scene 	*scene = ft_new_scene(cam); // нужна ли нам функция, когда одну сцену можно создать в стеке?
// 	t_figures	*fig = malloc(sizeof(t_figures));
// 	fig->type = SP;
// 	fig->fig.sp.centre = sphere_centre;
// 	fig->fig.sp.radius = 12/2;
// 	fig->color = 16777215;
// 	scene->ls_head_fig = ft_lstnew((void *)fig);
// 	scene->width = 800;
// 	scene->height = 600;
// 	mlx.vplane = ft_get_view_plane(scene->width, scene->height, scene->cams->fov); //создаем окно прсомотра

// 	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, scene->width, scene->height, "test");
// 	ft_ray_tracing(&mlx, scene);
// // ft_free_scene - функция, которяа освобождает все, что есть в сцене и саму сцену
// 	mlx_loop(mlx.mlx_ptr);
