/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:24:05 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:24:08 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int lol;

	if (!s1 || !s2)
		return (0);
	lol = 0;
	(ft_strncmp(s1, s2, n) == 0) ? lol += 1 : lol;
	return (lol);
}
