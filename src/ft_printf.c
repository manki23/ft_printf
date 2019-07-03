/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:00:08 by manki             #+#    #+#             */
/*   Updated: 2019/07/03 12:57:53 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_strlentoc(const char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		ret;
	char	*ptr;
	char	*ptr2;
	char	*output;

	ret = ft_strlen(format);
	if (ret > 0)
	{
		if (!(ptr = ft_strchr(format, '%')))
			ft_putstr(format);
		else
		{
			if (!(output = ft_strnew(ft_strlentoc(format, '%'))) ||
					!(output = ft_strsub(format, 0, ft_strlentoc(format, '%'))))
				return (-1);
			va_start(ap, format);
			while (ptr && ptr[0] == '%')
			{
				if (!(output = ft_strjoin(output, ft_conv(&ptr, &ap))))
					return (-1);
				if (!(ptr2 = ft_strchr(ptr, '%')))
					output = ft_strjoin(output, ptr);
				else
					output = ft_strjoin(output, ft_strsub(ptr, 0, ft_strlen(ptr)
								- ft_strlen(ptr2)));
				ptr = ptr2;
			}
			va_end(ap);
			ret = ft_strlen(output);
			ft_putstr(output);
		}
	}
	return (ret);
}
