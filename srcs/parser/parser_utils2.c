/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:41:46 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/22 21:57:43 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_iscomma(char **str)
{
	if (**str != ',')
		scene_error("parameters bad formatted\n");
	(*str)++;
}

t_color 	parse_color(char **str)
{
	int	r;
	int	g;
	int	b;
	t_color	color;

	r = 0;
	g = 0;
	b = 0;
	color.x = 0;
	color.y = 0;
	color.z = 0;
	color.w = COLOR;
	r |= ft_atoi_ptr(str);
	check_in_range(r, 0, 255, "colors must be in range [0, 255],");
	color.x = r;
	check_iscomma(str);
	g |= ft_atoi_ptr(str);
	check_in_range(g, 0, 255, "colors must be in range [0, 255],");
	color.y = g;
	check_iscomma(str);
	b |= ft_atoi_ptr(str);
	check_in_range(b, 0, 255, "colors must be in range [0, 255],");
	color.z = b;
	return (color);
}

t_vector	*parse_vec(char **str)
{
	t_vector	p;

	p.x = ft_atof(str);
	check_iscomma(str);
	p.y = ft_atof(str);
	check_iscomma(str);
	p.z = ft_atof(str);
	get_next(str);
	return (new_tuple(p.x, p.y, p.z, POINT));
}
