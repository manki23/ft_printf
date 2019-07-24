/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:34:38 by manki             #+#    #+#             */
/*   Updated: 2019/07/23 18:34:56 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_fill_mantissa(t_option opt, char *m, int op, double arg)
{
	char	*mant;
	int		precision;
	char	*zero;

	precision = 6;
	if ((opt.option & POINT) && (opt.precision != 6))
		precision = opt.precision;
	mant = ft_traduct(m, op, arg);
	if ((int)ft_strlen(mant) < precision)
	{
		zero = ft_strnew(precision - ft_strlen(mant));
		ft_memset(zero, '0', precision - ft_strlen(mant));
		mant = ft_strjoin(mant, zero);
	}
	else if (ft_strlen(mant) > 0)
		ft_round(mant, precision);
	if ((ft_strlen(mant) > 0 && mant[0] != 'a') || (opt.option & HASH))
	{
		mant = ft_strjoin(".", mant);
	}
	return (mant);
}

static char		*ft_get_value(t_option opt, char f_str[], double arg)
{
	char				*integ;
	unsigned long long	decim;
	long long			exp;
	char				*ret;
	int					nul;

	nul = ft_is_null(f_str, E_START, ft_strlen(f_str) - 1);
	exp = 0;
	if (!ft_is_null(f_str, E_START, ft_strlen(f_str) - 1))
		exp = (long long)ft_mul2_trash(f_str, 0, E_END) - E_BIAS;
	integ = ft_mul2_traduct(f_str, E_END, E_END + exp);
	if (!(ft_is_null(f_str, E_START, E_END) && !ft_is_null(f_str, M_START,
					M_END)) && !nul)
	{
		ret = ft_strpower("2", exp);
		integ = ft_stradd(integ, ret, ft_strlen(integ), ft_strlen(ret));
	}
	decim = ft_mul2_trash(f_str, E_END + exp, M_END);
	ret = ft_fill_mantissa(opt, ft_ulltoa(decim), M_END - E_END - exp, arg);
	ret = ft_strjoin(integ, ret);
	ret = ft_round2(ret, 0);
	if (f_str[0] == '1')
	{
		ret = ft_strjoin("-", ret);
	}
	return (ret);
}

/*
		ft_putstr("[");
		ft_putstr(integ);
		ft_putstr("]\n");
		*/
static char		*ft_fill_nb(t_option opt, double arg)
{
	char	*f_str;
	char	*nb;
	int		nul;

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
	if ((opt.option & PLUS) && ((arg > 0 || (nul == 1)) || ((nul == 2) &&
					(nb[0] != '-') && (nb[0] != 'n'))))
		nb = ft_strjoin("+", nb);
	else if ((opt.option & SPACE) && ((arg > 0 || (nul == 1)) ||
				((nul == 2) && (nb[0] != '-') && (nb[0] != 'n'))))
		nb = ft_strjoin(" ", nb);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb)
{
	char	*output;

	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!(opt.option & MINUS) && (opt.option & ZERO) &&
				(ft_isdigit(nb[0]) || ft_isdigit(nb[1])))
			ft_tr(output, ' ', '0');
		if (opt.option & MINUS)
			output = ft_strjoin(nb, output);
		else if (((((opt.option & PLUS) || (opt.option & SPACE)) &&
						(nb[0] != '-') && (opt.option & ZERO)) ||
					((opt.option & ZERO) && (nb[0] == '-'))) &&
				(ft_isdigit(nb[0]) || ft_isdigit(nb[1])))
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
	double		a;
	char		*output;

	if (opt.modif & LD_X)
	{
		a = va_arg(*ap, long double);
		size[0] = ft_strlen("0.000000");
		return ("0.000000");
	}
	a = va_arg(*ap, double);
	output = ft_fill_nb(opt, a);
	output = ft_fill_output(opt, output);
	size[0] = ft_strlen(output);
	return (output);
}
