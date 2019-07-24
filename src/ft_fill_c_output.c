/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_c_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:33:19 by manki             #+#    #+#             */
/*   Updated: 2019/07/22 19:24:59 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_fill_output(t_option opt, char *arg, size_t *size)
{
	char	*output;

	if (opt.width > (int)size[0])
	{
		size[0] += opt.width - size[0];
		output = ft_strnew(opt.width - 1);
		ft_memset(output, ' ', opt.width - 1);
		if (ft_read(&(opt.option), 2) && !ft_read(&(opt.option), 0))
			ft_tr(output, ' ', '0');
		if (ft_read(&(opt.option), 0))
			output = ft_strljoin(arg, output, 1, ft_strlen(output));
		else
			output = ft_strljoin(output, arg, ft_strlen(output), 1);
	}
	else
		output = ft_strjoin("", arg);
	return (output);
}

char			*ft_fill_c_output(t_option opt, va_list *ap, size_t *size)
{
	unsigned char	arg[2];
	char			*output;

	if (opt.flag & H_pourcent)
		arg[0] = '%';
	else
		arg[0] = va_arg(*ap, int);
	arg[1] = '\0';
	size[0] = 1;
	output = ft_fill_output(opt, (char *)arg, size);
	return (output);
}
