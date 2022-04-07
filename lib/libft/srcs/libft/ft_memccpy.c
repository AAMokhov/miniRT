/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:45:43 by mgarcia-          #+#    #+#             */
/*   Updated: 2022/03/11 21:09:06 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*s;
	unsigned char		*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n-- > 0)
	{
		*d++ = *s++;
		if (*(s - 1) == (unsigned char)c)
			return ((void *)d);
	}
	return (NULL);
}
