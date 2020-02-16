/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:20:34 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:20:36 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (src < dest)
		while (len--)
			((char *)dest)[len - 1] = ((const char *)src)[len - 1];
	else if (src > dest)
		ft_memcpy(dest, src, len);
	return (dest);
}
