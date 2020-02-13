/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:08:09 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 18:09:51 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
	counter = 0;
	while (*s)
	{
		dest[counter] = f(counter, *s);
		counter++;
		s++;
	}
	dest[counter + 1] = 0;
	return (dest);
}
