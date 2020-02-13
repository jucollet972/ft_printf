/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:14:17 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 06:06:27 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dest;
	size_t	counter;
	size_t	temp;

	counter = 0;
	temp = 0;
	if (!s)
		return (NULL);
	while (ft_trimspace(*s))
		s++;
	if (*s)
	{
		while (s[counter])
			counter++;
		while (!ft_isword(s[counter - 1]))
			counter--;
	}
	if (!(dest = ft_memalloc(counter + 1)))
		return (NULL);
	dest[counter] = 0;
	while (counter-- && *s)
		dest[temp++] = *(s++);
	return (dest);
}
