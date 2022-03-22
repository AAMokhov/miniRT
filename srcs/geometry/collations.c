/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:45:40 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/22 13:51:39 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_equal(float a, float b)
{
	return (ft_module(a - b) < EPSILON);
}

float	ft_max_module(float a, float b)
{
	if (a * (float)(1 - (2 * (a < 0))) > b * (float)(1 - (2 * (b < 0))))
		return (a * (float)(1 - (2 * (a < 0))));
	else
		return (b * (float)(1 - (2 * (b < 0))));
}

float	ft_min_module(float a, float b)
{
	if (a * (float)(1 - (2 * (a < 0))) < b * (float)(1 - (2 * (b < 0))))
		return (a * (float)(1 - (2 * (a < 0))));
	else
		return (b * (float)(1 - (2 * (b < 0))));
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_module(float a)
{
	if (a < 0)
		return (-1 * a);
	return (a);
}
