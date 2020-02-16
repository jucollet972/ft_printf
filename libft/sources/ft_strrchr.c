/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:24:23 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:24:25 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	counter;

	counter = (size_t)ft_strlen((char *)s);
	s = (char *)(s + counter);
	while (counter + 1)
	{
		if (*(char *)(s) == (char)c || (!*(char *)s && !c))
			return ((char *)(s));
		counter--;
		s--;
	}
	return (NULL);
}
