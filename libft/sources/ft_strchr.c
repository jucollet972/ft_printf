/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:57:02 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:47:37 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s || !c)
		return (NULL);
	while (*(char *)(s++) != (char)c)
		if (!*(char *)s && c != 0)
			return (NULL);
	return ((char *)(s - 1));
}
