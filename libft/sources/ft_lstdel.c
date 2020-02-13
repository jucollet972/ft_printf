/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 20:28:52 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 18:01:27 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *lst;

	lst = *alst;
	while (lst)
	{
		temp = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = temp;
	}
	*alst = NULL;
}
