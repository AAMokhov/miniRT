/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:15:25 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/15 01:15:20 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		parse(t_minilibx *mlx, t_scene *data, char **str_ptr)
{
	char *str;

	(void)mlx;
	str = *str_ptr;
	if (*str == 'A' && *(str++))
		parse_ambient_light(data, &str);
	else if (*str == 'C' && (*(str + 1) == 32 || *(str + 1) == 9) && *(str++))
		parse_camera(data, &str);
	else if (*str == 'c' && *(str + 1) == 'y' && *(str++) && *(str++))
		parse_cylinder(data->ls_head_fig, &str);
	// else if (*str == 'L' && (*(str + 1) == 32 || *(str + 1) == 9) && *(str++))
	// 	parse_light(&data, &str);
	// else if (*str == 's' && *(str + 1) == 'p' && *(str++) && *(str++))
	// 	parse_sphere(ls_fig, &str);
	// else if (*str == 'p' && *(str + 1) == 'l' && *(str++) && *(str++))
	// 	parse_plane(ls_fig, &str);
	*str_ptr = str;
}

static void		parse_elems(t_minilibx *mlx, t_scene *data, char *str)
{
	while (*str)
	{
		if (*str == '#')
		{
			while (*str && *str != '\n')
				str++;
		}
		else
			parse(mlx, data, &str);
		str++;
	}
	if (data->flg_ambl_light == 0 || data->cams == NULL)
		scene_error("Not enough elements to render a scene\n");
}

void			parse_scene(t_minilibx *mlx, t_scene *data, char **av)
{
	char		*str;
	int			fd;

	*data->ls_head_fig = NULL;
	// data->l = NULL;
	data->cams = NULL;
	write(1, "Parsing scene...\n", 17);
	str = (char *)enh_malloc(sizeof(char) * (BUFSIZE + 1));
	if ((fd = open(av[1], 0)) == -1)
		fatal("while opening file");
	str = readfile(str, fd);
	parse_elems(mlx, data, str);
	free(str);
}
