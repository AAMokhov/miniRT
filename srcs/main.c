/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:03:39 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/21 17:31:40 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene		data;

	if (argc != 2)
		ft_error_exit(-2);
	init_scene(&data);
	parse_scene(&data, argv);
	if (!init_mlx(&data))
		ft_error_exit(-1); // написать функцию raise_exception()
	if (!ft_get_view_plane(&data))
		ft_error_exit(-1); // написать функцию raise_exception()
	new_image(&data);

	graphic_loop(data);
	return(0);
}

void	init_scene(t_scene *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->canvas.img_ptr = NULL;
	data->canvas.img_adr = NULL;

	data->height = WIN_HEIGHT;
	data->width = WIN_WIDTH;

	data->canvas.w = data->width;
	data->canvas.h = data->height;

	data->ls_head_fig = NULL;
	data->light = NULL;
	data->cams = NULL;
	data->flg_ambl_light = 0;
	data->ambient_light = 0;
	data->amlight_color = 0;
}

int	init_mlx(t_scene *scene)
{
	scene->mlx_ptr = mlx_init();
	if (!scene->mlx_ptr)
		return (ERROR);
	scene->win_ptr = mlx_new_window(scene->mlx_ptr, scene->width, scene->height, "miniRT");
	if (!scene->win_ptr)
		return (ERROR);
	return (SUCCESS);
}

void		graphic_loop(t_scene data)
{
	mlx_hook(data.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_program, 0);
	mlx_hook(data.win_ptr, KEYPRESS, KEYPRESSMASK, key_hook, &data);
	mlx_loop(data.mlx_ptr);
}
