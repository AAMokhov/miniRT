/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:03:39 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/29 23:38:55 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_error_exit(int code)
{
	if (code == -2)
		write(STDERR_FILENO, "Error: Invalid aruments\n", 25);
	else if (code == -3)
		write(STDERR_FILENO, "MLX Error\n", 10);
	exit(EXIT_FAILURE);
}

void	*enh_malloc(unsigned int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		fatal("in malloc() on memory allocation");
	return (ptr);
}

void	scene_error(char *message)
{
	char	error_message[100];

	ft_strcpy(error_message, "Input Error: ");
	ft_strncat(error_message, message, 87);
	ft_putstr_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void	fatal(char *message)
{
	char	error_message[100];

	ft_strcpy(error_message, "[!!] Fatal Error ");
	ft_strncat(error_message, message, 83);
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	ft_mlx_pixel_put(t_image *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->img_adr + (y * canvas->line_length + x
			* (canvas->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
