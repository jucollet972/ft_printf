/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:23:34 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:23:37 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
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
