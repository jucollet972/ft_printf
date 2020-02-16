/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:22:11 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:22:15 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	counter;

	counter = 0;
	while (((unsigned char *)src)[counter])
	{
		((unsigned char*)dest)[counter] = ((unsigned char *)src)[counter];
		counter++;
	}
	((unsigned char*)dest)[counter] = 0;
	return (dest);
}
