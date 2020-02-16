/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:19:16 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:19:18 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_ull(unsigned long long n)
{
	size_t		index;
	char		*str;

	index = ft_count_ull(n);
	(n == 0) ? index = 1 : index;
	if (!(str = ft_strnew(index + 1)))
		return (NULL);
	while (index)
	{
		str[--index] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
