/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:21:17 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:21:19 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnendl(char const *s, size_t nb)
{
	if (!s || !nb)
		return ;
	while (*s && nb--)
		ft_putchar(*s++);
	ft_putchar('\n');
}
