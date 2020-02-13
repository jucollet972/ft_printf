/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striteri.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:49:55 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 18:50:29 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t counter;

	counter = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		f(counter, s);
		s++;
		counter++;
	}
	s -= counter;
}
