/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_s_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:03:23 by manki             #+#    #+#             */
/*   Updated: 2019/07/03 15:40:23 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char			*ft_fill_str(t_option opt, char *arg)
{
	char	*str;

	if (opt.point && !opt.precision)
		str = "";
	else if (opt.precision && ft_strlen(arg) > (size_t)opt.precision)
	{
		str = ft_strnew(opt.precision);
		ft_memcpy(str, arg, opt.precision);
	}
	else
		str = arg;
	return (str);
}

static char			*ft_fill_output(t_option opt, char *str)
{
	char	*output;

	if ((size_t)opt.width > ft_strlen(str))
	{
		output = ft_strnew(opt.width - ft_strlen(str));
		ft_memset(output, ' ', opt.width - ft_strlen(str));
		if (!opt.minus && !opt.point && opt.zero)
			ft_tr(output, ' ', '0');
		if (opt.minus)
			output = ft_strjoin(str, output);
		else
			output = ft_strjoin(output, str);
	}
	else
		output = str;
	return (output);
}

char				*ft_fill_s_output(t_option opt, va_list *ap)
{
	char		*output;
	char		*str;
	int			len;
	char		*arg;

	arg = va_arg(*ap, char *);
	len = opt.precision - ft_strlen(arg);
	str = ft_fill_str(opt, arg);
	output = ft_fill_output(opt, str);
	return (output);
}
/*
char				*ft_fill_s_output(t_option opt, va_list *ap	)
{
	char	*arg;
	char	*output;

	(void)opt;
	arg = va_arg(*ap, char *);
	output = ft_strjoin(arg, "");
	return (output);
}*/
