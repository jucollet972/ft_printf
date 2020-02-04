/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 19:05:46 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 06:03:59 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (src < dest)
		while (len--)
			((char *)dest)[len - 1] = ((const char *)src)[len - 1];
	else if (src > dest)
		ft_memcpy(dest, src, len);
	return (dest);
}
