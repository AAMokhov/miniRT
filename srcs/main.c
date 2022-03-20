/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:03:39 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/18 15:00:51 by dtentaco         ###   ########.fr       */
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
	data->width = 1200;
	data->height = 800;
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
	mlx_hook(mlx.win_ptr, KEYPRESS, KEYPRESSMASK, key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
