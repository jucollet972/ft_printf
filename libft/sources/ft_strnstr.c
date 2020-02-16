/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:24:17 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:24:19 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (needle[y] == '\0')
		return ((char *)haystack);
	while (haystack[x])
	{
		while (haystack[x + y] == needle[y] && x + y < len)
		{
			y++;
			if (needle[y] == '\0')
				return ((char *)haystack + x);
		}
		y = 0;
		x++;
	}
	return (NULL);
}
