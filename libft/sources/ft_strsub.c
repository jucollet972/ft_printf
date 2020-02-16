/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:24:53 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:24:55 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	counter;

	counter = 0;
	if (!s)
		return (NULL);
	if (!(dst = ft_memalloc(len + 1)))
		return (NULL);
	while (len--)
		dst[counter++] = ((char *)s)[start++];
	return (dst);
}
