/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_ull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:18:07 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:18:09 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_ull(unsigned long long n)
{
	size_t		counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}
