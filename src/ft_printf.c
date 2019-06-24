/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:00:08 by manki             #+#    #+#             */
/*   Updated: 2019/06/24 17:16:13 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_strlen_till_c(const char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	int		ret;
	char	*ptr;
	char	*output;

	ret = ft_strlen(format);
	if (ret > 0)
	{
		if (!(ptr = ft_strchr(format, '%')))
			ft_putstr(format);
		else
		{
			if (!(output = ft_strnew(ft_strlen_till_c(format, '%'))))
				return (-1);
			/*
			 *traitement du %
			 */
			va_start(ap, format);
			va_arg(ap, char *);
			va_end(ap);
			ret = ft_strlen(output);
			ft_putstr(output);
		}
	}
	return (ret);
}
