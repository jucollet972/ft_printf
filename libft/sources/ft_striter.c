/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:52:11 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 18:52:36 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	counter;

	counter = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		f(s);
		s++;
		counter++;
	}
	s -= counter;
}
