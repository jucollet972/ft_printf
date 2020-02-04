/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr_index.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/24 06:34:38 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 06:38:23 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchr_index(const char *s, int c)
{
	size_t	counter;

	counter = (size_t)ft_strlen((char *)s);
	s = (char *)(s + counter);
	while (counter + 1)
	{
		if (*(char *)(s) == (char)c || (!*(char *)s && !c))
			return (counter);
		counter--;
		s--;
	}
	return (-1);
}
