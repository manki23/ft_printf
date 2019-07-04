/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_c_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:33:19 by manki             #+#    #+#             */
/*   Updated: 2019/07/04 12:10:28 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_fill_output(t_option opt, char *arg, size_t *size)
{
	char	*output;

	if (opt.width > 1)
	{
		size[0] += opt.width - 1;
		output = ft_strnew(opt.width - 1);
		ft_memset(output, ' ', opt.width - 1);
		if (opt.zero && !opt.minus)
			ft_tr(output, ' ', '0');
		if (opt.minus)
			output = ft_strjoin(arg, output);
		else
			output = ft_strjoin(output, arg);
	}
	else
		output = arg;
	return (output);
}

char			*ft_fill_c_output(t_option opt, va_list *ap, size_t *size)
{
	char	arg[2];
	char	*output;

	if (opt.flag != '%')
		arg[0] = va_arg(*ap, int);
	else
		arg[0] = '%';
	arg[1] = '\0';
	size[0] = 1;
	output = ft_fill_output(opt, arg, size);
	return (output);
}
