/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:21:48 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:21:51 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s || !c)
		return (NULL);
	while (*(char *)(s++) != (char)c)
		if (!*(char *)s && c != 0)
			return (NULL);
	return ((char *)(s - 1));
}
