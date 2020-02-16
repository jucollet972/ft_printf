/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:22:51 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:22:54 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t counter;

	counter = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		f(counter, s);
		s++;
		counter++;
	}
	s -= counter;
}
