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

int	ft_equal(float a, float b)
{
	return (ft_module(a - b) < EPSILON);
}

float	ft_module(float a)
{
	if (a < 0)
		return (-1 * a);
	return (a);
}
