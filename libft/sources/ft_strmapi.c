/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:23:40 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:23:42 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
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
