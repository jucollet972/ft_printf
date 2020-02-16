/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:20:03 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:20:05 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
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
