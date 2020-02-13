/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:42:37 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 17:47:06 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_strlen_word(int counter, int c, const char *s, char **str)
{
	size_t	index_str;
	size_t	start;
	size_t	len;
	size_t	tab_index;

	index_str = 0;
	tab_index = 0;
	while (counter >= 0)
	{
		while (s[index_str] == c)
			index_str++;
		start = index_str;
		len = 0;
		while (s[index_str] != c && s[index_str])
		{
			len++;
			index_str++;
		}
		if (!(str[tab_index] = ft_strsub(s, start, len)))
			return (NULL);
		tab_index++;
		counter--;
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		counter;
	char	**str;

	if (!s | !c)
		return (NULL);
	counter = ft_count_word(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * counter + 1)))
		return (NULL);
	str[counter] = NULL;
	counter--;
	return (ft_strlen_word(counter, c, s, str));
}
