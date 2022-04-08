/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:53:10 by mgarcia-          #+#    #+#             */
/*   Updated: 2022/03/11 21:10:53 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (src == dst)
		return (dst);
	if (src < dst)
	{
		while (++i <= len)
			d[len - i] = s[len - i];
	}
	else
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	return (dst);
}
