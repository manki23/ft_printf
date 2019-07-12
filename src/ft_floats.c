/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:11:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/12 14:04:41 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>
static char		*ft_float_to_str(double arg)
{
	char	*ret;
	int		i;

	if (arg == 0)
	{
		ret = ft_strjoin("", "0");
			i = 0;
		while (++i <= M_END)
			ret = ft_strjoin(ret, "0");
	}
	else
		ret = ft_ulltoa_base(*(int64_t *)&arg, "01");
	if (arg > 0)
		ret = ft_strjoin("0", ret);
	if (ft_is_max(ret, E_START, E_END) && !ft_is_null(ret, M_START, M_END))
		return ("NaN");
	if (ft_is_max(ret, E_START, E_END) && ft_is_null(ret, M_START, M_END))
		return ("inf");
	return (ret);
}

static char		*ft_fill_mantissa(t_option opt, char *m, int op, double arg)
{
	char	*mantis;
	int		precision;
	char	*zero;
	char	*tmp;

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
	else
		mantis[precision] = '\0';
	tmp = ft_ulltoa_base(*(int64_t *)&arg, "01");
	if (ft_strlen(mantis) != 0 || !(opt.point && 
				(ft_is_null(tmp, 0, ft_strlen(tmp) == 1))) || opt.hashtag != 0)
	{
		if (ft_strlen(mantis) != 0)
			printf("1");
		if (!(opt.point && (ft_is_null(tmp, 0, ft_strlen(tmp)) == 1)))
			printf("2");
		if (opt.hashtag != 0)
			printf("3");
	printf("tmp = %d\n", ft_is_null(tmp, 0, ft_strlen(tmp)));
		mantis = ft_strjoin(".", mantis);
	}
	return (mantis);
}

static char		*ft_get_value(t_option opt, char f_str[], double arg)
{
	unsigned long long	integ;
	unsigned long long	decim;
	long long			exp;
	char				*ret;

	exp = (long long)ft_mul2(f_str, 0, E_END);
	if (arg != 0)
		exp -= E_BIAS;
	integ = ft_mul2(f_str, E_END, E_END + exp);
	if (!(ft_is_null(f_str, E_START, E_END) && !ft_is_null(f_str, M_START, 
					M_END)) && arg != 0)
		integ += ft_ipower(2, exp);
	decim = ft_mul2(f_str, E_END + exp, M_END);
	ret = ft_fill_mantissa(opt, ft_ulltoa(decim), M_END - E_END - exp, arg);
	ret = ft_strjoin(ft_ulltoa(integ), ret);
	if (f_str[0] == '1')
		ret = ft_strjoin("-", ret);
	return (ret);
}

static char		*ft_fill_nb(t_option opt, double arg)
{
	//int len = opt.precision - ft_nblen(arg);
	char	*f_str;
	char	*nb;

	f_str = ft_float_to_str(arg);
	if (!ft_strcmp(f_str, "NaN") || !ft_strcmp(f_str, "inf"))
		return (f_str);
	nb = ft_get_value(opt, f_str, arg);
	if (opt.plus && arg >= 0)
		nb = ft_strjoin("+", nb);
	else if (opt.space && arg >= 0)
		nb = ft_strjoin(" ", nb);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb, double arg)
{
	char	*output;

	if (opt.width > (int)ft_strlen(nb))
	{
//	printf("(%s)", nb);
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!opt.minus && opt.zero)
			ft_tr(output, ' ', '0');
		if (opt.minus)
			output = ft_strjoin(nb, output);
		else if (((opt.plus || opt.space) && arg >= 0 && opt.zero)
				|| (opt.zero && arg < 0))
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
	double		arg;
	char		*output;

	arg = va_arg(*ap, double);
	if (!opt.l && !opt.ld)
		arg = (float)arg;
	output = ft_fill_nb(opt, arg);
	output = ft_fill_output(opt, output, arg);
	size[0] = ft_strlen(output);
	return (output);
}
