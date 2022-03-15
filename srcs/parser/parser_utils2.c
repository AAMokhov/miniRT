/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:41:46 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/15 23:01:06 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_iscomma(char **str)
{
	if (**str != ',')
		scene_error("parameters bad formatted\n");
	(*str)++;
}

int			parse_color(char **str)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	r |= ft_atoi_ptr(str);
	check_in_range(r, 0, 255, "colors must be in range [0, 255],");
	r <<= 16;
	check_iscomma(str);
	g |= ft_atoi_ptr(str);
	check_in_range(g, 0, 255, "colors must be in range [0, 255],");
	g <<= 8;
	check_iscomma(str);
	b |= ft_atoi_ptr(str);
	check_in_range(b, 0, 255, "colors must be in range [0, 255],");
	return (r | g | b);
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
	return (ft_new_vec(p.x, p.y, p.z));
}
