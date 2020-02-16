/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:23:58 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:24:01 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	counter;

	counter = 0;
	while (*src && counter < len)
		dest[counter++] = *src++;
	ft_bzero(dest + counter, len - counter);
	return (dest);
}
