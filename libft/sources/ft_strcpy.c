/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:53:48 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 18:54:10 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	counter;

	counter = 0;
	while (((unsigned char *)src)[counter])
	{
		((unsigned char*)dest)[counter] = ((unsigned char *)src)[counter];
		counter++;
	}
	((unsigned char*)dest)[counter] = 0;
	return (dest);
}
