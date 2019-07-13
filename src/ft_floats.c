/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:11:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/13 13:55:31 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>
/*static char		*ft_float_to_str(double arg)
{
	char	*ret;
	int		i;

	ret = ft_ulltoa_base(*(int64_t *)&arg, "01");
	if ((int)ft_strlen(ret) < M_END + 1)
	{
		i = (int)ft_strlen(ret) - 1;
		while (++i <= M_END)
			ret = ft_strjoin(ret, "0");
	}
	ft_afficher_bit(ret, 8);
	if (arg > 0)
		ret = ft_strjoin("0", ret);
	if (ft_is_max(ret, E_START, E_END) && !ft_is_null(ret, M_START, M_END))
		return ("nan");
	if (ft_is_max(ret, 0, E_END) && ft_is_null(ret, M_START, M_END))
		return("-inf");
	if (ft_is_max(ret, E_START, E_END) && ft_is_null(ret, M_START, M_END))
		return ("inf");
	return (ret);
}

static char		*ft_fill_mantissa(t_option opt, char *m, int op, double arg)
{
	char	*mantis;
	int		precision;
	char	*zero;

	precision = 6;
	if (opt.point && (opt.precision != 6))
		precision = opt.precision;
	mantis = ft_traduct(m, op, arg);
	if ((int)ft_strlen(mantis) < precision)
	{
		zero = ft_strnew(precision - ft_strlen(mantis));
		ft_memset(zero, '0', precision - ft_strlen(mantis));
		mantis = ft_strjoin(mantis, zero);
	}
	else if (ft_strlen(mantis) > 0)
		mantis[precision] = '\0';
	//printf("m = [%s] | mantis = [%s]\n", m, mantis);
	if ((ft_strlen(mantis) > 0) || opt.hashtag)
		mantis = ft_strjoin(".", mantis);
	return (mantis);
}

static char		*ft_get_value(t_option opt, char f_str[], double arg)
{
	unsigned long long	integ;
	unsigned long long	decim;
	long long			exp;
	char				*ret;
	int					nul;

	nul = ft_is_null(f_str, 1, ft_strlen(f_str) - 1);
	if (!nul)
		exp = (long long)ft_mul2(f_str, 0, E_END) - E_BIAS;
	else
		exp = 0;
	integ = ft_mul2(f_str, E_END, E_END + exp);
	if (!(ft_is_null(f_str, E_START, E_END) && !ft_is_null(f_str, M_START, 
					M_END)) && !nul)
		integ += ft_ipower(2, exp);
	decim = ft_mul2(f_str, E_END + exp, M_END);
	//printf("exp = %lld | integ = %llu | decim = %llu\n", exp, integ, decim);
	ret = ft_fill_mantissa(opt, ft_ulltoa(decim), M_END - E_END - exp, arg);
	ret = ft_strjoin(ft_ulltoa(integ), ret);
	if (f_str[0] == '1')
		ret = ft_strjoin("-", ret);
	return (ret);
}

static char		*ft_fill_nb(t_option opt, double arg)
{
	char	*f_str;
	char	*nb;
	int		nul;

	f_str = ft_float_to_str(arg);
	if (!ft_strcmp(f_str, "nan") || !ft_strcmp(f_str, "inf") ||
			!ft_strcmp(f_str, "-inf"))
		return (f_str);
	nb = ft_get_value(opt, f_str, arg);
	nul = ft_is_null(f_str, 0, ft_strlen(f_str) - 1);
	if (opt.plus && (arg > 0 || nul))
		nb = ft_strjoin("+", nb);
	else if (opt.space && (arg > 0 || nul))
		nb = ft_strjoin(" ", nb);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb)
{
	char	*output;

	if (opt.width > (int)ft_strlen(nb))
	{
	//		printf("(%s)", nb);
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!opt.minus && opt.zero)
			ft_tr(output, ' ', '0');
		if (opt.minus)
			output = ft_strjoin(nb, output);
		else if (((opt.plus || opt.space) && (nb[0] != '-') && opt.zero)
				|| (opt.zero && (nb[0] == '-')))
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
}*/

char			*ft_fill_f_output(t_option opt, va_list *ap, size_t *size)
{
	//double		arg;
	void			*arg;
	double			tab[2];
//	char		*output;
	char		*ret;

	arg = va_arg(*ap, void *);
//	tab[0] = (arg & 0xFFFFFFFFFFFFFFFF0000000000000000) >> 64;
//	tab[1] = (arg & 0x0000000000000000FFFFFFFFFFFFFFFF);
	ret = ft_ulltoa_base(*(int64_t *)&tab[0], "01");
	ft_afficher_bit(ret, 8);
	ret = ft_ulltoa_base(*(int64_t *)&tab[1], "01");
	ft_afficher_bit(ret, 8);
	size[0] = 0;
	(void)opt;
	return ("");
	//if (!opt.l && !opt.ld)
	//	arg = (float)arg;
/*	output = ft_fill_nb(opt, arg);
	output = ft_fill_output(opt, output);
	size[0] = ft_strlen(output);
	return (output);*/
}
