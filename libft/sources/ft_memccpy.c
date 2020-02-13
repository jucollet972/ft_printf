/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 16:43:43 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 16:44:57 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		(*(unsigned char*)(dst++)) = (*(unsigned char*)(src++));
		if ((*(unsigned char*)(src)) == (unsigned char)c)
			return ((unsigned char*)(dst + 1));
	}
	return (NULL);
}
