/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_word.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 15:18:18 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 16:05:35 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
