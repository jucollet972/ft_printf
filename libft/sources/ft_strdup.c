/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:22:29 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:22:33 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char			*new;
	unsigned int	counter;

	counter = 0;
	while (src[counter])
		counter++;
	if (!(new = (char *)malloc(sizeof(char) * (counter + 1))))
		return (NULL);
	counter = 0;
	while (src[counter])
	{
		new[counter] = src[counter];
		counter++;
	}
	new[counter] = '\0';
	return (new);
}
