/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isword.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 15:18:35 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 16:06:16 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_isword(char c)
{
	return (c >= 33 && c <= 126);
}
