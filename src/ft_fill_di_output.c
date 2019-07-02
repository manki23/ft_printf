/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_di_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:21:52 by manki             #+#    #+#             */
/*   Updated: 2019/07/02 19:28:54 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_fill_nb(t_option opt, int len, long long arg)
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

static char		*ft_fill_output(t_option opt, char *nb, long long arg)
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
		else if (((opt.plus || opt.space) && arg >= 0 && opt.zero && !opt.minus
					&& !opt.point) || (!opt.minus && !opt.point && opt.zero &&
						arg < 0))
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

int				ft_if_short_mod(t_option opt, int arg)
{
	int		mod;

	mod = 0;
	if (opt.hh)
		mod = 256;
	else if (opt.h)
		mod = 65536;
	while ((opt.hh || opt.h) && arg > ((mod / 2) - 1))
		arg -= mod;
	while ((opt.hh || opt.h) && arg < -(mod / 2))
		arg += mod;
	return (arg);
}

#include <stdio.h>

char			*ft_fill_di_output(t_option opt, va_list *ap)
{
	char		*output;
	char		*nb;
	int			len;
	long long	arg;

	arg = va_arg(*ap, long long);
	if (opt.l)
		arg = (long)arg;
	else if (!opt.ll && !opt.l)
		arg = ft_if_short_mod(opt, arg);
	len = opt.precision - ft_nblen(arg);
	nb = ft_fill_nb(opt, len, arg);
	output = ft_fill_output(opt, nb, arg);
	return (output);
}
