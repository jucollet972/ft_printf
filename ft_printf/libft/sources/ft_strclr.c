/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strclr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:56:12 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 18:56:42 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return ;
	while (s[size])
		size++;
	ft_bzero(s, size);
}
