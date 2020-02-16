/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:23:20 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:23:24 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	j = 0;
	i = 0;
	len = 0;
	while (dst[i])
		i++;
	len += size < i ? size : i;
	while (src[j] && j < size - len)
	{
		dst[i++] = src[j++];
	}
	while (src[j])
		j++;
	i -= size <= i ? 1 : 0;
	i += len >= size ? 1 : 0;
	dst[i] = '\0';
	return (len + j);
}
