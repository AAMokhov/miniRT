/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:24:11 by mgarcia-          #+#    #+#             */
/*   Updated: 2022/03/11 21:11:30 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
