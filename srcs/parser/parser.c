/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:15:25 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/29 22:39:21 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		parse(t_scene *data, char **str_ptr)
{
	char *str;

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

static void		parse_elems(t_scene *data, char *str)
{
	while (*str)
	{
		if (*str == '#')
		{
			while (*str && *str != '\n')
				str++;
		}
		else
			parse(data, &str);
		str++;
	}
	if (data->flg_ambl_light == 0 || data->cams == NULL)
		scene_error("Not enough elements to render a scene\n");
}

void 		print_obj(t_scene *data)
{
	t_figures	*ls_ptr;
	t_list		*ls_head;
	int			i = 0;

	printf("\nAmb light = %f\n", data->ambient_light);
	printf("Amb color: [%f,%f,%f]\n\n", data->amlight_color.x, data->amlight_color.y, data->amlight_color.z);

	printf("Cams:\nO: x=%f, y=%f, z=%f\n", data->cams->origin->x,data->cams->origin->y, data->cams->origin->z);
	printf("D: x=%f, y=%f, z=%f\n", data->cams->direction->x, data->cams->direction->y, data->cams->direction->z);
	printf("FOV: %f\n\n", data->cams->fov);

	if (data->light)
	{
		printf("Light:\nO: x=%f, y=%f, z=%f\n", data->light->origin->x, data->light->origin->y, data->light->origin->z);
		printf("Brightness: %f\n", data->light->br);
		printf("Color: [%f,%f,%f]\n\n", data->light->color.x, data->light->color.y, data->light->color.z);
	}

	if (data->ls_head_fig)
	{
		ls_head = data->ls_head_fig;
		while (ls_head)
		{
			ls_ptr = (t_figures *)(ls_head->content);
			if (ls_ptr->type == SP)
			{
				printf("%d - SPHERE\n", i);
				printf("Center: x=%f, y=%f, z=%f\n",ls_ptr->fig.sp.centre->x, ls_ptr->fig.sp.centre->y, ls_ptr->fig.sp.centre->z);
				printf("Rad: %f\n", ls_ptr->fig.sp.radius);
			}
			else if (ls_ptr->type == PL)
			{
				printf("%d - PLANE\n", i);
				printf("Point: x=%f, y=%f, z=%f\n", ls_ptr->fig.pl.centre->x,
													ls_ptr->fig.pl.centre->y,
													ls_ptr->fig.pl.centre->z);
			}
			else if (ls_ptr->type == CY)
			{
				printf("%d - CYLINDER\n", i);
				printf("Center: x=%f, y=%f, z=%f\n", ls_ptr->fig.cy.centre->x, ls_ptr->fig.cy.centre->y, ls_ptr->fig.cy.centre->z);
				printf("Height: %f\n", ls_ptr->fig.cy.height);
				printf("Rad: %f\n", ls_ptr->fig.cy.radius);
			}
			if (ls_ptr->normal != NULL)
				printf("Norm: x=%f, y=%f, z=%f\n",ls_ptr->normal->x, ls_ptr->normal->y, ls_ptr->normal->z);
			printf("Color: [%f,%f,%f]\n\n", ls_ptr->color.x, ls_ptr->color.y, ls_ptr->color.z);
			printf("\n");
			ls_head = ls_head->next;
			i++;
		}

	}
}

void		parse_scene(t_scene *data, char **av)
{
	char		*str;
	int			fd;

	write(1, "Parsing scene...\n", 17);
	str = (char *)enh_malloc(sizeof(char) * (BUFSIZE + 1));
	if ((fd = open(av[1], 0)) == -1)
		fatal("while opening file");
	str = readfile(str, fd);
	parse_elems(data, str);
	free(str);
	print_obj(data);
	write(1, "Finished parsing.\n", 18);
}
