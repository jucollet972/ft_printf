/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:18:14 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:18:16 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_word(const char *s, char c)
{
	size_t	index;
	size_t	counter;

	counter = 0;
	index = 0;
	while (s[index])
	{
		(s[index + 1] == c && s[index] != c) ? counter++ : counter;
		(!s[index + 1] && s[index] != c) ? counter++ : counter;
		index++;
	}
	return (counter);
}
