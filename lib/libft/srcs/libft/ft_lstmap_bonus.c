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
	if (!(list = ft_lstnew((*f)(lst->content))))
		return (NULL);
	begin_list = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&begin_list, del);
			return (NULL);
		}
		list = list->next;
	}
	return (begin_list);
}
