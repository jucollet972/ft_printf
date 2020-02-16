/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:21:55 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:21:58 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr_index(const char *str, int c)
{
	int		index;

	index = 0;
	if (str == NULL)
		return (-1);
	while (str[index])
	{
		if (str[index++] == c)
			return (index);
	}
	return (-1);
}
