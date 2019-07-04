/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:00:08 by manki             #+#    #+#             */
/*   Updated: 2019/07/04 13:49:19 by manki            ###   ########.fr       */
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

static void		ft_analyze(char *ptr, t_list *out, va_list *ap)
{
	char		*ptr2;
	char		*content;
	size_t		size;

	while (ptr && ptr[0] == '%')
	{
		content = ft_conv(&ptr, ap, &size);
		ft_lsadd(&out, content, size);
		if (!(ptr2 = ft_strchr(ptr, '%')))
			ft_lsadd(&out, ptr, ft_strlen(ptr));
		else
			ft_lsadd(&out, ptr, ft_strlen(ptr) - ft_strlen(ptr2));
		ptr = ptr2;
	}
	va_end(*ap);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ret;
	char		*ptr;
	t_list		*out;

	ret = ft_strlen(format);
	if (ret > 0)
	{
		if (!(ptr = ft_strchr(format, '%')))
			ft_putstr(format);
		else
		{
			if (!(out = ft_lstnew((char *)format, ft_strlentoc(format, '%'))))
				return (-1);
			va_start(ap, format);
			ft_analyze(ptr, out, &ap);
			ft_lstprint(out);
			ret = ft_lst_content_size(out);
		}
	}
	return (ret);
}
