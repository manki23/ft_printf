/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:00:08 by manki             #+#    #+#             */
/*   Updated: 2019/07/28 16:14:52 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				ft_strlentoc(const char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void		ft_savelines(int *track, size_t size, char *tab, int *ret)
{
	if (track[0] + size > BUFFER_SIZE)
	{
		write(1, tab, track[0]);
		tab = ft_memset(tab, '\0', BUFFER_SIZE);
		ret[0] += track[0];
		track = 0;
	}
}
/*
static char		*ft_overflow(char *str, size_t *size, int *ret)
{
	int		i;
	char	*result;

	i = 0;
	while (size[0] > BUFFER_SIZE)
	{
		write(1, &str[i], BUFFER_SIZE);
		i += BUFFER_SIZE;
		ret[0] += BUFFER_SIZE;
		size -= BUFFER_SIZE;
	}
	result = ft_memalloc(size[0] + 1);
	ft_memcpy(result, &str[i], size[0]);
	ft_strdel(&str);
	return (result);
}*/

static int		ft_analyze(char *ptr, va_list *ap, int *ret)
{
	char		*ptr2;
	char		*content;
	size_t		size;
	char		*tab;
	int			track;

	tab = ft_memalloc(BUFFER_SIZE);
	track = 0;
	while (ptr && ptr[0] == '%')
	{
		content = ft_conv(&ptr, ap, &size);
	//	if (size > BUFFER_SIZE)
	//		content = ft_overflow(content, &size, ret);
		if (size > 0)
		{
			ft_savelines(&track, size, tab, ret);
			ft_memcpy(&tab[track], content, size);
			ft_strdel(&content);
			track += size;
		}
		if (!(ptr2 = ft_strchr(ptr, '%')))
		{
			ft_savelines(&track, size, tab, ret);
			ft_memcpy(&tab[track], ptr, ft_strlen(ptr));
			track += ft_strlen(ptr);
		}
		else
		{
			ft_savelines(&track, size, tab, ret);
			ft_memcpy(&tab[track], ptr, ft_strlen(ptr) - ft_strlen(ptr2));
			track += ft_strlen(ptr) - ft_strlen(ptr2);
		}
		ptr = ptr2;
	}
	va_end(*ap);
	ret[0] += track;
	write(1, tab, track);
	ft_strdel(&tab);
	return (track);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ret;
	char		*ptr;
	t_list		*out;

	ret = 0;
	if (format)
	{
		if (!(ptr = ft_strchr(format, '%')))
			ret += write(1, format, ft_strlentoc(format, '%'));
		else
		{
			ret += write(1, format, ft_strlentoc(format, '%'));
			out = NULL;
			va_start(ap, format);
			ft_analyze(ptr, &ap, &ret);
		}
	}
	return (ret);
}
