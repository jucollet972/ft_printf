/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:19:13 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:19:14 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_ll(long long n)
{
	size_t		index;
	char		*str;
	int			sign;

	sign = 0;
	index = ft_count_long_long(n);
	if ((unsigned long long)n == -9223372036854775808U)
		return (ft_strdup("-9223372036854775808"));
	(n == 0) ? index = 1 : index;
	(n < 0) ? index++ : 0;
	(n < 0) ? sign++ : 0;
	(n < 0) ? n *= -1 : 0;
	if (!(str = ft_strnew(index + 1)))
		return (NULL);
	while (index)
	{
		str[--index] = (n % 10) + 48;
		n /= 10;
	}
	(sign > 0) ? *str = '-' : *str;
	return (str);
}
