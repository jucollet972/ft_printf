/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:24:48 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:24:50 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		need_index;
	char	*haystack_temp;

	need_index = 0;
	haystack_temp = (char *)haystack;
	if (!*needle)
		return (haystack_temp);
	while (*haystack_temp)
	{
		need_index = 0;
		while (needle[need_index] == *haystack_temp)
		{
			need_index++;
			haystack_temp++;
			if (!needle[need_index])
				return (haystack_temp - need_index);
		}
		if (needle[need_index])
			haystack_temp -= need_index;
		haystack_temp++;
	}
	return (NULL);
}
