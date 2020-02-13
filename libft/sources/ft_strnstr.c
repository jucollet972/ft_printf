/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:59:42 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 20:15:11 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (needle[y] == '\0')
		return ((char *)haystack);
	while (haystack[x])
	{
		while (haystack[x + y] == needle[y] && x + y < len)
		{
			y++;
			if (needle[y] == '\0')
				return ((char *)haystack + x);
		}
		y = 0;
		x++;
	}
	return (NULL);
}
