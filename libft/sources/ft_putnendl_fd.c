/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:21:22 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:21:24 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnendl_fd(char const *s, size_t nb, int fd)
{
	if (!s || !nb)
		return ;
	while (*s && nb--)
		ft_putchar_fd(*s++, fd);
	ft_putchar('\n');
}
