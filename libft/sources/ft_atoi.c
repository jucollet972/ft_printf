/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:17:08 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:17:16 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int	res;
	int				sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if ((*str == '+' && *(str + 1) == '-') ||
			(*str == '-' && *(str + 1) == '+'))
		return (0);
	else if (*str == '-')
	{
		str++;
		sign *= -1;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = 10 * res + (*str++ - 48);
	return (res * sign);
}
