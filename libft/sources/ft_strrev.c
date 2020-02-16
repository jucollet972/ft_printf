/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:24:34 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:33:28 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *ref)
{
	char	temp;
	int		start;
	int		end;
	char	*str;

	start = 0;
	end = 0;
	if (!(str = ft_strdup(ref)))
		return (NULL);
	while (str[end])
		end++;
	while (end > start)
	{
		temp = str[--end];
		str[end] = str[start];
		str[start] = temp;
		start++;
	}
	return (str);
}
