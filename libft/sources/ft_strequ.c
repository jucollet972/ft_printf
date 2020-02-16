/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:22:40 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:22:42 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	lol;

	if (!s1 || !s2)
		return (0);
	lol = 0;
	(ft_strcmp(s1, s2) == 0) ? lol += 1 : lol;
	return (lol);
}
