/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_f_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:58:01 by manki             #+#    #+#             */
/*   Updated: 2019/07/05 13:10:01 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>
static char		*ft_fill_nb(t_option opt, int len, long double arg)
{
	char	*zero;
	char	*nb;

	if (ft_nblen(arg) < opt.precision)
	{
		zero = ft_strnew(len);
		ft_memset(zero, '0', len);
		nb = ft_lltoa(arg);
		if (arg < 0)
		{
			nb = ft_strjoin(zero, &nb[1]);
			zero[0] = '-';
			zero[1] = '\0';
		}
		nb = ft_strjoin(zero, nb);
	}
	else if (arg == 0 && opt.point && !opt.precision)
		nb = "";
	else
		nb = ft_lltoa(arg);
	if (opt.plus && arg >= 0)
		nb = ft_strjoin("+", nb);
	else if (opt.space && arg >= 0)
		nb = ft_strjoin(" ", nb);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb, long double arg)
{
	char	*output;

	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!opt.minus && !opt.point && opt.zero)
			ft_tr(output, ' ', '0');
		if (opt.minus)
			output = ft_strjoin(nb, output);
		else if (((opt.plus || opt.space) && arg >= 0 && opt.zero && !opt.point)
				|| (!opt.point && opt.zero && arg < 0))
		{
			output = ft_strjoin(output, &nb[1]);
			nb[1] = '\0';
			output = ft_strjoin(nb, output);
		}
		else
			output = ft_strjoin(output, nb);
	}
	else
		output = nb;
	return (output);
}

char			*ft_fill_f_output(t_option opt, va_list *ap, size_t *size)
{
	char		*output;
	char		*nb;
	int			len;
	long double	arg;

	arg = va_arg(*ap, long double);
	if (opt.l)
		arg = (double)arg;
	else if (!opt.ll && !opt.l)
		arg = (float)arg;
	len = opt.precision - ft_nblen(arg);
	nb = ft_fill_nb(opt, len, arg);
	output = ft_fill_output(opt, nb, arg);
	size[0] = ft_strlen(output);
	return (output);
}
//	ft_putstr("{");
//	ft_putstr(ft_lltoa(len));
//	ft_putstr("}");
