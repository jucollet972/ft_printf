/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:21:06 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:21:09 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int res;

	res = (long int)n;
	if (res < 0)
	{
		ft_putchar('-');
		res *= -1;
	}
	if (res <= 9)
		ft_putchar(res + '0');
	else if (res > 9)
	{
		ft_putnbr(res / 10);
		ft_putchar(res % 10 + '0');
	}
}
