/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 18:54:13 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 19:02:47 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
