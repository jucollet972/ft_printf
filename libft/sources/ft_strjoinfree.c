/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:23:06 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:23:16 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int mod)
{
	size_t	counter;
	char	*new;
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	if (!s1 || !s2)
		return (NULL);
	counter = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = ft_memalloc(counter + 1)))
		return (NULL);
	while (s1[index2])
		new[index++] = s1[index2++];
	index2 = 0;
	while (s2[index2])
		new[index++] = s2[index2++];
	if (mod == 1 || mod == 3)
		ft_strdel(&s1);
	if (mod == 2 || mod == 3)
		ft_strdel(&s2);
	return (new);
}
