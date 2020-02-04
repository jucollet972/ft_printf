/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 18:33:10 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 19:56:53 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict dest, const char *restrict src, size_t n)
{
	size_t		lol;

	lol = 0;
	while (dest[lol])
		lol++;
	while (n && *src)
	{
		dest[lol] = *src;
		lol++;
		src++;
		n--;
	}
	dest[lol] = 0;
	return (dest);
}
