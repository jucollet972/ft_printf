/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:10:02 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 18:10:51 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	counter;
	char	*dest;

	counter = 0;
	if (!s)
		return (NULL);
	while (s[counter])
		counter++;
	if (!(dest = ft_memalloc(counter + 1)))
		return (NULL);
	while (*s)
	{
		*dest = f(*s);
		dest++;
		s++;
	}
	*(dest + 1) = 0;
	dest -= counter;
	return (dest);
}
