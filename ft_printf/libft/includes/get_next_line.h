/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <jucollet@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 15:55:54 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 21:21:35 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <fcntl.h>
# include "libft.h"
# include <unistd.h>

typedef	struct		s_lst
{
	char			*str;
	int				fd;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(const int fd, char **line);
#endif
