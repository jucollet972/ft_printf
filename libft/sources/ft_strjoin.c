/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:22:58 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:23:01 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	counter;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	counter = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = ft_memalloc(counter + 1)))
		return (NULL);
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
	return (new - counter);
}
