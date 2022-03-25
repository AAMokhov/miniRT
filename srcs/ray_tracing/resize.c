/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:01:55 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/23 23:13:17 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	resize(t_figures* this, float size)
{
	this->resize_func(this, size);
}

void	resize_sp(void* this, float size)
{
	t_figures *sphere;

	sphere = (t_figures *)this;
	sphere->fig.sp.diameter = sphere->fig.sp.radius * 2;
	if (sphere->fig.sp.diameter * size <= EPSILON)
		return ;
	sphere->fig.sp.diameter *= size;
	sphere->fig.sp.squared_radius = pow(sphere->fig.sp.radius, 2.0);
}

void	resize_pl(void* this, float size)
{
	(void)this;
	(void)size;
}

void	resize_cy(void* this, float size)
{
	t_figures *cylinder;

	cylinder = (t_figures *)this;
	if (cylinder->fig.cy.radius * 2 * size <= EPSILON)
		return ;
	cylinder->fig.cy.radius *= size;
	cylinder->fig.cy.squared_radius = pow(cylinder->fig.cy.radius, 2.0);
}
