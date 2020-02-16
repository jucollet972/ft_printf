/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:22:45 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:22:48 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	counter;

	counter = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		f(s);
		s++;
		counter++;
	}
	s -= counter;
}
