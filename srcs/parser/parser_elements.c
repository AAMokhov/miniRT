/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:29:17 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/15 01:21:00 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_cylinder(t_list **is_head_fig, char **str)
{
	t_figures	*new_fig;

	new_fig = enh_malloc(sizeof(t_figures));
	ft_lstadd_back(is_head_fig, ft_lstnew(new_fig));
	new_fig->type = CY;
	get_next(str);
	new_fig->fig.cy.centre = parse_vec(str);
	new_fig->fig.cy.direction = parse_vec(str);
	ft_vec_normalize(new_fig->fig.cy.direction);
	new_fig->fig.cy.radius = ft_atof(str) / 2;
	check_in_range(new_fig->fig.cy.radius, 0, INFINITY, "cylinder");
	new_fig->fig.cy.height = ft_atof(str);
	check_in_range(new_fig->fig.cy.height, 0, INFINITY, "cylinder");
	new_fig->color = parse_color(str);
}
