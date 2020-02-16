/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:16:26 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:16:28 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
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
