/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:11:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/21 15:54:18 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

#include <stdio.h>
static char		*ft_fill_mantissa(t_option opt, char *m, int op, double arg)
{
	char	*mantis;
	int		precision;
	char	*zero;
//	char	*tmp;

	precision = 6;
	if (opt.point && (opt.precision != 6))
		precision = opt.precision;
	mantis = ft_traduct(m, op, arg);
	if ((int)ft_strlen(mantis) < precision)
	{
		zero = ft_strnew(precision - ft_strlen(mantis));
		ft_memset(zero, '0', precision - ft_strlen(mantis));
//		tmp = mantis;
		mantis = ft_strjoin(mantis, zero);
//		ft_strdel(&tmp);
//		ft_strdel(&zero);
	}
	else if (ft_strlen(mantis) > 0)
		ft_round(mantis, precision);
	if ((ft_strlen(mantis) > 0 && mantis[0] != 'a') || opt.hashtag)
	{
//		tmp = mantis;
		mantis = ft_strjoin(".", mantis);
//		ft_strdel(&tmp);
	}
	return (mantis);
}

static char		*ft_get_value(t_option opt, char f_str[], double arg)
{
	unsigned long long	integ;
	unsigned long long	decim;
	long long			exp;
	char				*ret;
	int					nul;
//	char				*tmp;

	nul = ft_is_null(f_str, 1, ft_strlen(f_str) - 1);
	exp = 0;
	if (!nul)
		exp = (long long)ft_mul2(f_str, 0, E_END) - E_BIAS;
	integ = ft_mul2(f_str, E_END, E_END + exp);
	if (!(ft_is_null(f_str, E_START, E_END) && !ft_is_null(f_str, M_START,
					M_END)) && !nul)
		integ += ft_ipower(2, exp);
	decim = ft_mul2(f_str, E_END + exp, M_END);
	ret = ft_fill_mantissa(opt, ft_ulltoa(decim), M_END - E_END - exp, arg);
//	tmp = ret;
	ret = ft_strjoin(ft_ulltoa(integ), ret);
//	ft_strdel(&tmp);
	ret = ft_round2(ret, 0);
	if (f_str[0] == '1')
	{
//		tmp = ret;
		ret = ft_strjoin("-", ret);
//		ft_strdel(&tmp);
	}
	return (ret);
}

static char		*ft_fill_nb(t_option opt, double arg)
{
	char	*f_str;
	char	*nb;
	int		nul;
//	char	*tmp;

	f_str = ft_float_to_str(arg);
	if (!ft_strcmp(f_str, "nan") || !ft_strcmp(f_str, "inf") ||
			!ft_strcmp(f_str, "-inf"))
	{
		nul = 2;
		nb = f_str;
	}
	else
	{
		nb = ft_get_value(opt, f_str, arg);
		nul = ft_is_null(f_str, 0, ft_strlen(f_str) - 1);
	}
//	tmp = nb;
	if (opt.plus && ((arg > 0 || (nul == 1)) || ((nul == 2) && (nb[0] != '-') &&
					(nb[0] != 'n'))))
		nb = ft_strjoin("+", nb);
	else if (opt.space && ((arg > 0 || (nul == 1)) ||
				((nul == 2) && (nb[0] != '-') && (nb[0] != 'n'))))
		nb = ft_strjoin(" ", nb);
//	if (((opt.plus || opt.space) && ((arg > 0 || (nul == 1)) || ((nul == 2) &&
//						(nb[0] != '-') && (nb[0] != 'n')))))
//		ft_strdel(&tmp);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb)
{
	char	*output;
//	char	*tmp;

	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!opt.minus && opt.zero && (ft_isdigit(nb[0]) || ft_isdigit(nb[1])))
			ft_tr(output, ' ', '0');
//		tmp = output;
		if (opt.minus)
			output = ft_strjoin(nb, output);
		else if ((((opt.plus || opt.space) && (nb[0] != '-') && opt.zero)
				|| (opt.zero && (nb[0] == '-'))) && (ft_isdigit(nb[0]) ||
				ft_isdigit(nb[1])))
		{
			output = ft_strjoin(output, &nb[1]);
//			ft_strdel(&tmp);
//			tmp = output;
			nb[1] = '\0';
			output = ft_strjoin(nb, output);
		}
		else
			output = ft_strjoin(output, nb);
//		ft_strdel(&tmp);
	}
	else
		output = nb;
//	ft_strdel(&nb);
	return (output);
}

char			*ft_fill_f_output(t_option opt, va_list *ap, size_t *size)
{
	double		a;
	char		*output;

	a = va_arg(*ap, double);
	output = ft_fill_nb(opt, a);
	output = ft_fill_output(opt, output);
	size[0] = ft_strlen(output);
	return (output);
}
