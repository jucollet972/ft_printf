/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 18:00:50 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 06:16:51 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict dest, const char *restrict src)
{
	size_t		index;

	index = 0;
	while (dest[index])
		index++;
	while (*src)
		dest[index++] = *src++;
	dest[index++] = '\0';
	return (dest);
}
