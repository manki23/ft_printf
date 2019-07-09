/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_f_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:58:01 by manki             #+#    #+#             */
/*   Updated: 2019/07/09 15:02:11 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <limits.h>

#define E_START 1
#define E_END 11
#define M_START 12
#define M_END 63
#define E_BIAS 1023

static char		*ft_fill_nb(t_option opt, double arg)
{
	char	*nb;

	if (arg == 0 && opt.point && !opt.precision)
		nb = "";
	else
		nb = ft_lltoa(arg);
	if (opt.plus && arg >= 0)
		nb = ft_strjoin("+", nb);
	else if (opt.space && arg >= 0)
		nb = ft_strjoin(" ", nb);
	return (nb);
}

#include <stdio.h>
static void		ft_afficher_bit(char *str, int mod)
{
	int		i;

	ft_putstr("[");
	i = -1;
	while (++i < (int)ft_strlen(str))
	{
		ft_putchar(str[i]);
		if (!((i + 1 ) % mod))
			ft_putchar(' ');
	}
	ft_putstr("]\n");
}

static t_byte	ft_is_max(char *bit_nb, int from, int to)
{
	while (from <= to)
	{
		if (bit_nb[from] != '1')
			return (0);
		from++;
	}
	return (1);
}

static t_byte	ft_is_null(char *bit_nb, int from, int to)
{
	while (from <= to)
	{
		if (bit_nb[from] != '0')
			return (0);
		from++;
	}
	return (1);
}

static char		*ft_interpreteur(char *f_str)
{
	long long	i;
	long long	e;
	long long	nb;
	long long	dec;
	long long	j;

	if (ft_is_max(f_str, E_START, E_END) && !ft_is_null(f_str, M_START, M_END))
		return ("NaN");
	if (ft_is_max(f_str, E_START, E_END) && ft_is_null(f_str, M_START, M_END))
		return ("inf");
	if (ft_is_null(f_str, E_START, E_END) && ft_is_null(f_str, M_START, M_END))
		return ("0");
	i = 0;
	e = 0;
	while (++i <= E_END)
	{
		if (f_str[i] == '1')
		{
			e += ft_ipower(2, E_END - i);
		}
	}
	j = 0;
	if (ft_is_null(f_str, E_START, E_END) && !ft_is_null(f_str, M_START, M_END))
	{
	}
	else
	{
		nb = 0;
		nb += ft_ipower(2, e - E_BIAS);
		j = e - E_BIAS;
		i--;
		while (++i <= M_END && --j >= 0)
		{
			if (f_str[i] == '1')
				nb += ft_ipower(2, j);
		}
	}
	dec = 0;
	while (++i <= M_END)
	{
		if (f_str[i] == '1')
		{
			//dec += ft_ipower(2, (i - E_END - (e - E_BIAS)));
			dec += ft_ipower(2, M_END - i);
		}
	}
	if (f_str[0] == '1')
		printf("-%lld.%lld\n", nb, dec);
	else
		printf("%lld.%lld\n", nb, dec);
	return ("");
}

static char		*ft_fill_decimal(t_option opt, double arg)
{
	int		precision;
	char	*nb;
	int64_t	copy;
	char	*f_str;

	precision = 6;
	if (opt.point && (opt.precision != 6))
		precision = opt.precision;
	copy = *(int64_t*)&arg;
	f_str = ft_ulltoa_base(copy, "01");
	if (ft_strlen(f_str) < sizeof(copy) * CHAR_BIT)
		f_str = ft_strjoin("0", f_str);
	ft_interpreteur(f_str);
	ft_afficher_bit(f_str, 8);
	if (arg > 0)
		nb = ft_lltoa(arg);
	else
		nb = ft_lltoa(-arg);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb, double arg)
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
	double	arg;

	arg = va_arg(*ap, double);
	//if (opt.l)
	//	arg = (double)arg;
	//else if (!opt.ll && !opt.l)
	//	arg = (float)arg;
	nb = ft_fill_nb(opt, arg);
	nb = ft_strjoin(nb, ".");
	nb = ft_strjoin(nb, ft_fill_decimal(opt, arg));
	output = ft_fill_output(opt, nb, arg);
	size[0] = ft_strlen(output);
	return (output);
}
//	ft_putstr("{");
//	ft_putstr(ft_lltoa(len));
//	ft_putstr("}");
