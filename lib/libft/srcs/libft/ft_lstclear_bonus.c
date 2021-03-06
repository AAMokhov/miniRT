/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:02:00 by mgarcia-          #+#    #+#             */
/*   Updated: 2022/03/11 21:08:37 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_link;
	t_list	*link;

	link = *lst;
	while (link)
	{
		next_link = link->next;
		(*del)(link->content);
		free(link);
		link = next_link;
	}
	*lst = NULL;
}
