/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:18:51 by mgarcia-          #+#    #+#             */
/*   Updated: 2022/03/11 21:09:26 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_list;
	t_list	*list;

	if (!lst)
		return (NULL);
	list = ft_lstnew((*f)(lst->content));
	if (!list)
		return (NULL);
	begin_list = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = ft_lstnew((*f)(lst->content));
		if (!list->next)
		{
			ft_lstclear(&begin_list, del);
			return (NULL);
		}
		list = list->next;
	}
	return (begin_list);
}
