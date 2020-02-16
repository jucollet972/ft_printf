/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:17:24 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:29:09 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_base_char(int nb, char c)
{
	char ret_c;

	ret_c = 0;
	if (nb <= 9 && nb >= 0)
		ret_c = nb + 48;
	else if (c == 'x')
		ret_c = nb + 97 - 10;
	else if (c == 'X' && nb > 9)
		ret_c = nb + 65 - 10;
	return (ret_c);
}
