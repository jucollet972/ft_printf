/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:19:58 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:20:00 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *mem;

	if (!size)
		return (NULL);
	if (!(mem = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
