/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:21:12 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:21:14 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int res;

	res = (long int)n;
	if (res < 0)
	{
		ft_putchar_fd('-', fd);
		res *= -1;
	}
	if (res <= 9)
		ft_putchar_fd(res + '0', fd);
	else if (res > 9)
	{
		ft_putnbr_fd(res / 10, fd);
		ft_putchar_fd(res % 10 + '0', fd);
	}
}
