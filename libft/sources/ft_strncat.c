/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:23:45 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:23:47 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict dest, const char *restrict src, size_t n)
{
	size_t		lol;

	lol = 0;
	while (dest[lol])
		lol++;
	while (n && *src)
	{
		dest[lol] = *src;
		lol++;
		src++;
		n--;
	}
	dest[lol] = 0;
	return (dest);
}
