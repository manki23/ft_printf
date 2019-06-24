/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:36:09 by manki             #+#    #+#             */
/*   Updated: 2019/06/05 13:21:28 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/ft_printf.h"

static int		ft_putformat(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
		}
		if (str[i] && str[i] == '%')
			;
	}
	return (i);
}

int				ft_printf(const char * restrict format, ...)
{
	int			i;
	va_list		list;

	i = 0;
	i = ft_putformat((char *)format);
	va_start(list, format);
	va_end(list);
	return (ft_strlen(format));
}
