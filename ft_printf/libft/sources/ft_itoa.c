/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 15:19:27 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 15:51:21 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t		index;
	char		*str;
	int			signe;

	signe = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	index = ft_count_integer(n);
	(n == 0) ? index = 1 : index;
	(n < 0) ? index++ : 0;
	(n < 0) ? signe++ : 0;
	(n < 0) ? n *= -1 : 0;
	if (!(str = ft_strnew(index + 1)))
		return (NULL);
	while (index)
	{
		str[--index] = (n % 10) + 48;
		n /= 10;
	}
	(signe > 0) ? *str = '-' : *str;
	return (str);
}
