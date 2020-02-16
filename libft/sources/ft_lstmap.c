/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:19:47 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:19:49 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dest;
	t_list	*temp;
	t_list	*start;

	temp = f(lst);
	if (!(dest = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	start = dest;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(dest->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		dest = dest->next;
		lst = lst->next;
	}
	return (start);
}
