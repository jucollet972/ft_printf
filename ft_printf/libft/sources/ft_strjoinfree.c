/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoinfree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/25 21:50:07 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/25 21:50:10 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
	while (s1[index])
		new[index++] = s1[index2++];
	while (s2[index2])
		new[index++] = s2[index2++];
	if (mod == 1 || mod == 3)
		free(s1);
	else if (mod == 2 || mod == 3)
		free(s2);
	return (new);
}
