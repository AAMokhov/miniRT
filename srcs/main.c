/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:03:39 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/11 23:16:34 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{

	t_minilibx	mlx;
	t_vector vec;
	float x;
	float y;
	float z;

	x = 3.4;
	y = 5.0;
	z = 1.2;
	(void)argc;
	(void)argv;
	(void)mlx;
	printf("test\n");
	vec = *ft_new_vec(x, y, z);
	return(0);
}