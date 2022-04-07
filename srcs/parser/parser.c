/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:15:25 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/31 21:42:43 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse(t_scene *data, char **str_ptr)
{
	char	*str;

	str = *str_ptr;
	if (*str == 'A' && *(str++))
		parse_ambient_light(data, &str);
	else if (*str == 'C' && (*(str + 1) == 32 || *(str + 1) == 9) && *(str++))
		parse_camera(data, &str);
	else if (*str == 'c' && *(str + 1) == 'y' && *(str++) && *(str++))
		parse_cylinder(&data->ls_head_fig, &str);
	else if (*str == 'L' && (*(str + 1) == 32 || *(str + 1) == 9) && *(str++))
		parse_light(&data->light, &str);
	else if (*str == 's' && *(str + 1) == 'p' && *(str++) && *(str++))
		parse_sphere(&data->ls_head_fig, &str);
	else if (*str == 'p' && *(str + 1) == 'l' && *(str++) && *(str++))
		parse_plane(&data->ls_head_fig, &str);
	*str_ptr = str;
}

static void	parse_elems(t_scene *data, char *str)
{
	while (*str && str)
	{
		if (*str == '#')
		{
			while (*str && *str != '\n')
				str++;
		}
		else
			parse(data, &str);
		if (*str == '\0')
			break ;
		str++;
	}
	if (data->flg_ambl_light == 0 || data->cams == NULL)
		scene_error("Not enough elements to render a scene\n");
}

void	parse_scene(t_scene *data, char **av)
{
	char		*str;
	int			fd;
	size_t		len;

	len = ft_strlen(av[1]);
	if (av[1][len - 1] != 't' && av[1][len - 2] != 'r' && av[1][len - 3] != '.')
		scene_error("This type of file is not allowed\n");
	write(1, "Parsing scene...\n", 17);
	str = (char *)enh_malloc(sizeof(char) * (1));
	str[0] = '\0';
	fd = open(av[1], 0);
	if (fd == -1)
		fatal("while opening file");
	str = readfile(str, fd);
	parse_elems(data, str);
	free(str);
	print_obj(data);
	write(1, "Finished parsing.\n", 18);
}

void	print_obj(t_scene *data)
{
	t_figures	*ls_ptr;
	t_list		*ls_head;
	int			i;

	i = 0;
	print_staff(data);
	if (data->ls_head_fig)
	{
		ls_head = data->ls_head_fig;
		while (ls_head)
		{
			ls_ptr = (t_figures *)(ls_head->content);
			if (ls_ptr->type == SP)
				print_sphere(ls_ptr, i);
			else if (ls_ptr->type == PL)
				print_plane(ls_ptr, i);
			else if (ls_ptr->type == CY)
				print_cylinder(ls_ptr, i);
			print_extra(ls_ptr);
			ls_head = ls_head->next;
			i++;
		}
	}
}
