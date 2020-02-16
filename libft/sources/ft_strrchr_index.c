/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:24:29 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:24:32 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchr_index(const char *s, int c)
{
	size_t	counter;

	counter = (size_t)ft_strlen((char *)s);
	s = (char *)(s + counter);
	while (counter + 1)
	{
		if (*(char *)(s) == (char)c || (!*(char *)s && !c))
			return (counter);
		counter--;
		s--;
	}
	return (-1);
}
