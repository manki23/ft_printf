/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_s_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:03:23 by manki             #+#    #+#             */
/*   Updated: 2019/07/27 17:31:28 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char			*ft_fill_str(t_option opt, char *arg)
{
	char	*str;

	if ((opt.option & POINT) && !opt.precision)
		str = ft_memalloc(2);
	else if (arg && opt.precision && ft_strlen(arg) > (size_t)opt.precision)
	{
		str = ft_memalloc(opt.precision + 1);
		ft_memcpy(str, arg, opt.precision);
	}
	else if (arg)
	{
		str = ft_memalloc(ft_strlen(arg) + 1);
		str = (char *)ft_memcpy(str, arg, ft_strlen(arg));
	}
	else
	{
		str = ft_memalloc(7);
		if (opt.precision && (7 > (size_t)opt.precision))
			str = ft_strncat(str, "(null)", opt.precision);
		else
			str = ft_strcat(str, "(null)");
	}
	return (str);
}

static char			*ft_fill_output(t_option o, char *str)
{
	char	*output;
	char	*tmp;

	if ((size_t)o.width > ft_strlen(str))
	{
		output = ft_memalloc(o.width + 1);
		str = ft_realloc(str, o.width + 1);
		ft_memset(output, ' ', o.width - ft_strlen(str));
		if (!(o.option & MINUS) && !(o.option & POINT) && (o.option & ZERO))
			ft_tr(output, ' ', '0');
		if (o.option & MINUS)
		{
			tmp = output;
			output = ft_strcat(str, output);
			ft_strdel(&tmp);
		}
		else
		{
			output = ft_strcat(output, str);
			ft_strdel(&str);
		}
	}
	else
		output = str;
	return (output);
}

char				*ft_fill_s_output(t_option opt, va_list *ap, size_t *size)
{
	char		*output;
	char		*arg;

	arg = va_arg(*ap, char *);
	output = ft_fill_str(opt, arg);
	output = ft_fill_output(opt, output);
	size[0] = ft_strlen(output);
	if (size[0] == 0)
		ft_strdel(&output);
	return (output);
}
