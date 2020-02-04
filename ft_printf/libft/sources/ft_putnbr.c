/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 19:00:36 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 19:01:37 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
