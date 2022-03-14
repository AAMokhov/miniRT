/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:03:39 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/15 01:10:10 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minilibx	mlx;
	t_scene		data;
//	t_vector vec;

	if (argc != 2)
		ft_error_exit(-2);
	parse_scene(&mlx, &data, argv);

	//TEST
	// t_vector  *sphere_centre = ft_new_vec(3, 2, -32);
	// t_sphere 	*sphere = ft_new_sphere(sphere_centre, 12/2);
	// t_vector 	*cam_orign = ft_new_vec(0, 0, 0); //нужна функция для преобразования любых координат
	// t_vector 	*cam_direction = ft_new_vec(0, 0, -1); //||-||-||
	// t_camera 	*cam = ft_new_cam(cam_orign, cam_direction, 70);
	// t_scene 	*scene = ft_new_scene(cam, sphere);
	// scene->width = 800;
	// scene->height = 600;

	// mlx.mlx_ptr = mlx_init();
	// mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, scene->width, scene->height, "test");
	// ft_ray_tracing(mlx.mlx_ptr, mlx.win_ptr, scene);
// ft_free_scene - функция, которяа освобождает все, что есть в сцене и саму сцену
	// mlx_loop(mlx.mlx_ptr);

	return(0);
}
