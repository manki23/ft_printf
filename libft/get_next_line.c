/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:19:49 by manki             #+#    #+#             */
/*   Updated: 2018/01/14 14:04:15 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		ft_fill_line(char **line, t_gnl *s)
{
	while (s->i < s->r)
	{
		s->len += 1;
		if (!(*line = ft_realloc(*line, s->len + 1)))
			return (-1);
		if (s->buf[s->i] == '\n')
		{
			s->i++;
			s->len = 0;
			return (1);
		}
		line[0][s->len - 1] = s->buf[s->i];
		line[0][s->len] = '\0';
		s->i++;
	}
	if (s->i == 0 && s->r == 0)
		return (0);
	return (2);
}

t_gnl	*ft_find_fd(const int fd, t_gnl tab[])
{
	int		i;

	i = 0;
	while (i < FD && tab[i].fd != fd)
		i++;
	if (i < FD && tab[i].fd == fd)
		return (&tab[i]);
	else
	{
		i = 0;
		while (i < FD && tab[i].fd != 0)
			i++;
		tab[i].fd = fd;
		return (&tab[i]);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	tab[FD];
	t_gnl			*s;
	int				result;

	if ((line == NULL) || (fd < 0) || (fd > FD) || !(*line = ft_strnew(0)))
		return (-1);
	result = 3;
	s = ft_find_fd(fd, tab);
	if ((s->i < s->r) && ((result = ft_fill_line(line, s)) != 2))
		return (result);
	while (result == 3 || result == 2)
	{
		s->i = 0;
		if ((s->r = read(s->fd, s->buf, BUFF_SIZE)) == -1)
			return (-1);
		if (s->r == 0 && result == 2)
			return (1);
		result = ft_fill_line(line, s);
		if (result != 2)
			return (result);
	}
	return (-1);
}
