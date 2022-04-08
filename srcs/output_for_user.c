/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_for_user.c					                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:15:25 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/31 21:42:43 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_staff(t_scene *data)
{
	printf("\nAmb light = %f\n", data->ambient_light);
	printf("Amb color: [%f,%f,%f]\n\n", data->amlight_color.x,
		data->amlight_color.y, data->amlight_color.z);
	printf("Cams:\nO: x=%f, y=%f, z=%f\n", data->cams->origin->x,
		data->cams->origin->y, data->cams->origin->z);
	printf("D: x=%f, y=%f, z=%f\n", data->cams->direction->x,
		data->cams->direction->y, data->cams->direction->z);
	printf("FOV: %f\n\n", data->cams->fov);
	if (data->light)
	{
		printf("Light:\nO: x=%f, y=%f, z=%f\n", data->light->origin->x,
			data->light->origin->y, data->light->origin->z);
		printf("Brightness: %f\n", data->light->br);
		printf("Color: [%f,%f,%f]\n\n", data->light->color.x,
			data->light->color.y, data->light->color.z);
	}
}

void	print_sphere(t_figures *ls_ptr, int i)
{
	printf("%d - SPHERE\n", i);
	printf("Center: x=%f, y=%f, z=%f\n", ls_ptr->fig.sp.centre->x,
		ls_ptr->fig.sp.centre->y, ls_ptr->fig.sp.centre->z);
	printf("Rad: %f\n", ls_ptr->fig.sp.radius);
}

void	print_plane(t_figures *ls_ptr, int i)
{
	printf("%d - PLANE\n", i);
	printf("Point: x=%f, y=%f, z=%f\n", ls_ptr->fig.pl.centre->x,
		ls_ptr->fig.pl.centre->y, ls_ptr->fig.pl.centre->z);
}

void	print_cylinder(t_figures *ls_ptr, int i)
{
	printf("%d - CYLINDER\n", i);
	printf("Center: x=%f, y=%f, z=%f\n", ls_ptr->fig.cy.centre->x,
		ls_ptr->fig.cy.centre->y, ls_ptr->fig.cy.centre->z);
	printf("Height: %f\n", ls_ptr->fig.cy.height);
	printf("Rad: %f\n", ls_ptr->fig.cy.radius);
}

void	print_extra(t_figures *ls_ptr)
{
	if (ls_ptr->normal != NULL)
		printf("Norm: x=%f, y=%f, z=%f\n", ls_ptr->normal->x,
			ls_ptr->normal->y, ls_ptr->normal->z);
	printf("Color: [%f,%f,%f]\n\n", ls_ptr->color.x,
		ls_ptr->color.y, ls_ptr->color.z);
	printf("\n");
}
