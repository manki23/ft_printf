/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_s_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:03:23 by manki             #+#    #+#             */
/*   Updated: 2019/07/22 17:22:06 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char			*ft_fill_str(t_option opt, char *arg)
{
	char	*str;

	if (ft_read(&(opt.option), 5) && !opt.precision)
		str = "";
	else if (arg && opt.precision && ft_strlen(arg) > (size_t)opt.precision)
	{
		str = ft_strnew(opt.precision);
		ft_memcpy(str, arg, opt.precision);
	}
	else if (arg)
		str = arg;
	else
	{
		str = ft_strjoin("", "(null)");
		if (opt.precision && ft_strlen(str) > (size_t)opt.precision)
			str[opt.precision] = '\0';
	}
	return (str);
}

static char			*ft_fill_output(t_option opt, char *str)
{
	char	*output;
	char	*tmp;

	if ((size_t)opt.width > ft_strlen(str))
	{
		output = ft_strnew(opt.width - ft_strlen(str));
		ft_memset(output, ' ', opt.width - ft_strlen(str));
		if (!ft_read(&(opt.option), 0) && !ft_read(&(opt.option), 5) &&
				ft_read(&(opt.option), 2))
			ft_tr(output, ' ', '0');
		tmp = output;
		if (ft_read(&(opt.option), 0))
			output = ft_strjoin(str, output);
		else
			output = ft_strjoin(output, str);
		ft_strdel(&tmp);
	}
	else
		output = str;
	return (output);
}

char				*ft_fill_s_output(t_option opt, va_list *ap, size_t *size)
{
	char		*output;
	char		*str;
	char		*arg;

	arg = va_arg(*ap, char *);
	str = ft_fill_str(opt, arg);
	output = ft_fill_output(opt, str);
	size[0] = ft_strlen(output);
	return (output);
}
