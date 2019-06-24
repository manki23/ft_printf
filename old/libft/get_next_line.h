/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:20:00 by manki             #+#    #+#             */
/*   Updated: 2018/01/15 11:53:05 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"

# define BUFF_SIZE 32
# define FD 42000

typedef struct		s_gnl
{

	int				i;
	int				r;
	char			buf[BUFF_SIZE];
	int				len;
	int				fd;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
