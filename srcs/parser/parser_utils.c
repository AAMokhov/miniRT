/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:26:09 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/15 23:00:52 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char		*readfile(char *str, int fd)
{
	char	buf[BUFSIZE + 1];
	char	*ptr;
	int		ret;

	while ((ret = read(fd, buf, BUFSIZE)) > 0)
	{
		ptr = str;
		buf[ret] = '\0';
		if (!(str = ft_strjoin(str, buf)))
			return (NULL);
		free(ptr);
	}
	return (str);
}

void	get_next(char **str)
{
	while (**str == 32 || **str == 9)
		(*str)++;
}

float	ft_atof(char **str)
{
	int		num_int;
	float	num_dec;
	int		sign;

	num_int = 0;
	sign = 1;
	if (**str == '-' && *((*str)++))
		sign = -1;
	while (ft_isdigit(**str))
		num_int = num_int * 10 + (*((*str)++) - '0');
	if (**str == '.')
		(*str)++;
	num_dec = 0.0;
	while (ft_isdigit(**str))
		num_dec = num_dec * 10 + (*((*str)++) - '0');
	while (num_dec >= 1)
		num_dec /= 10;
	num_dec += num_int;
	get_next(str);
	return (num_dec * sign);
}

int		ft_atoi_ptr(char **str)
{
	int i;
	int	neg;

	i = 0;
	neg = 1;
	if (**str == '-' && *((*str)++))
		neg = -1;
	while (ft_isdigit(**str))
		i = i * 10 + (*((*str)++) - '0');
	get_next(str);
	return (i * neg);
}

void	check_in_range(float nb, float min, float max, char *str_obj)
{
	char	error_message[100];

	if (nb < min || nb > max)
	{
		ft_strncpy(error_message, str_obj, 76);
		ft_strcat(error_message, " parameter out of range\n");
		scene_error(error_message);
	}
}
