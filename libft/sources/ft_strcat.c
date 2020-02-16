/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:21:42 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:21:44 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
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
