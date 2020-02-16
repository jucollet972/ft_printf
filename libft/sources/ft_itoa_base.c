/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:19:09 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:32:07 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long long n, int base, char c)
{
	char				*ret_str;
	unsigned long long	temp;
	int					len;
	int					index;

	index = 0;
	temp = n;
	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (temp /= base)
		len++;
	if (!(ret_str = ft_strnew(len + 1)))
		return (NULL);
	while (n > 0)
	{
		ret_str[len--] = ft_base_char(n % base, c);
		n /= base;
	}
	return (ret_str);
}
