/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnendl_fd.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/24 00:29:19 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 00:34:04 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnendl_fd(char const *s, size_t nb, int fd)
{
	if (!s || !nb)
		return ;
	while (*s && nb--)
		ft_putchar_fd(*s++, fd);
	ft_putchar('\n');
}
