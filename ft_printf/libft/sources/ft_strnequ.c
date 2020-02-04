/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnequ.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:05:19 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 22:17:48 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
