/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_f_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:58:01 by manki             #+#    #+#             */
/*   Updated: 2019/07/10 17:21:01 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <limits.h>

#define E_START 1
#define E_END 11
#define M_START 12
#define M_END 63
#define E_BIAS 1023

#include <stdio.h>
static char		*ft_sign(t_option opt, char *nb)
{

	if (opt.plus && nb[0] != '-')
		nb = ft_strjoin("+", nb);
	else if (opt.space && nb[0] != '-')
		nb = ft_strjoin(" ", nb);
	return (nb);
}

static char		*ft_interpreteur(char f_str[], double f)
{
	long long	i;
	long long	e;
	unsigned long long	dec;
	char				*m;

	i = 0;
	e = 0;
	while (++i <= E_END)
		if (f_str[i] == '1')
			e += ft_ipower(2, E_END - i);
	if (ft_is_null(f_str, E_START, E_END) && !ft_is_null(f_str, M_START, M_END))
	{
	}
	else if ((i + (e - E_BIAS)) <= M_END)
		i += e - E_BIAS;
	dec = 0;
	while (++i <= M_END)
		if (f_str[i] == '1')
			dec += ft_ipower(2, M_END - i);
	m = ft_traduct(ft_ulltoa(dec), M_END - E_END - (e - E_BIAS), f);
	m = ft_strjoin(".", m);
	return (m);
}

static char		*ft_check_f_str(char f_str[])
{
	if (ft_strlen(f_str) < M_END + 1)
		return ("ok");
	if (ft_is_max(f_str, E_START, E_END) && !ft_is_null(f_str, M_START, M_END))
		return ("NaN");
	if (ft_is_max(f_str, E_START, E_END) && ft_is_null(f_str, M_START, M_END))
		return ("inf");
	return ("ok");
}

static char		*ft_fill_mantissa(t_option opt, char *f_str, double arg)
{
	int		precision;
	char	*mantissa;
	int		len;
	char	*zero;

		precision = 6;
		if (opt.point && (opt.precision != 6))
			precision = opt.precision;
	if (arg != 0)
	{
		mantissa = ft_interpreteur(f_str, arg);
		mantissa[precision + 1] = '\0';
	}
	else
		mantissa = ft_strjoin("", "");
	if ((int)ft_strlen(mantissa) < (precision + 1))
	{
		if (mantissa[0] != '.')
			mantissa = ft_strjoin(".", mantissa);
		len = ft_strlen(mantissa) - (precision + 1);
		zero = ft_strnew(len);
		ft_memset(zero, '0', len);
		mantissa = ft_strjoin(mantissa, zero);
	}
	return (mantissa);
}

static char		*ft_fill_decimal(t_option opt, double arg)
{
	char	*nb;
	char	*f_str;
	char	*mantissa;

	if (arg == 0)
	{
		nb = ft_strjoin("", "0");
		mantissa = ft_fill_mantissa(opt, "", arg);
	}
	else
	{
		f_str = ft_ulltoa_base(*(int64_t*)&arg, "01");
		if (ft_strlen(f_str) < sizeof(int64_t) * CHAR_BIT)
			f_str = ft_strjoin("0", f_str);
		if (ft_strcmp(ft_check_f_str(f_str), "ok") != 0)
			return (ft_check_f_str(f_str));
		nb = ft_lltoa(arg);
		mantissa = ft_fill_mantissa(opt, f_str, arg);
	}
	nb = ft_strjoin(nb, mantissa);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb, double arg)
{
	char	*output;

	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!opt.minus && opt.zero)
			ft_tr(output, ' ', '0');
		if (opt.minus)
			output = ft_strjoin(nb, output);
		else if (((opt.plus || opt.space) && arg > 0 && opt.zero)
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



char			*ft_error(t_option opt, va_list *ap, size_t *size)
{
	char		*output;
	double		arg;

	arg = va_arg(*ap, double);
	//if (opt.l)
	//	arg = (double)arg;
	//if (!opt.ll && !opt.l)
	//	arg = (float)arg;
	output = ft_fill_decimal(opt, arg);
	output = ft_sign(opt, output);
	if (ft_strcmp(output, "NaN") != 0 && ft_strcmp(output, "inf") != 0)
		output = ft_fill_output(opt, output, arg);
	size[0] = ft_strlen(output);
	return (output);
	
	//size[0] = 0;
	//return ("");
}
