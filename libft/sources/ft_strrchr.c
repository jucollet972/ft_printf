/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:58:34 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 23:13:53 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	counter;

	counter = (size_t)ft_strlen((char *)s);
	s = (char *)(s + counter);
	while (counter + 1)
	{
		if (*(char *)(s) == (char)c || (!*(char *)s && !c))
			return ((char *)(s));
		counter--;
		s--;
	}
	return (NULL);
}
