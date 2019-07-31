/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fvalue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:43:32 by manki             #+#    #+#             */
/*   Updated: 2019/07/31 11:30:31 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_cut_mantissa(t_option opt, char *nb)
{
	t_coord		c;

	if (!((opt.option & POINT) && (opt.precision != 6 && opt.precision >= 0)))
		opt.precision = 6;
	c.i = -1;
	c.j = -1;
	while (c.j == -1 && nb[++c.i])
		if (nb[c.i] == '.')
			c.j = c.i;
	while (nb[c.i] && ((c.i - c.j) < opt.precision))
		c.i++;
	if (nb[c.i] && ((c.i - c.j) == opt.precision))
		nb = ft_roundd(nb, c.i, &c.j, opt.precision);
	else if (nb[c.i] == '\0' && ((c.i - c.j) < opt.precision))
	{
		nb = ft_realloc(nb, opt.precision + c.j + 2);
		while (++c.i - 1 <= (opt.precision + c.j))
			nb[c.i - 1] = '0';
	}
	if (opt.precision == 0 && !(opt.option & HASH))
		nb = ft_realloc(nb, c.j + 1);
	if (opt.precision == 0 && !(opt.option & HASH))
		nb[c.j] = '\0';
	return (nb);
}

static char		ft_fill_hidbit(t_define var, char f_str[], int iexp)
{
	char	hidden_bit;

	hidden_bit = '0';
	if ((!ft_is_null(f_str, var.m_start, var.m_end)) ||
			!ft_is_null(f_str, var.e_start, var.m_end))
		hidden_bit = '1';
	if ((iexp == 1 - var.e_bias) || (var.buf == LDB_BUF))
		hidden_bit = '0';
	return (hidden_bit);
}

static int		ft_fill_iexp(char f_str[], t_define var)
{
	int		iexp;
	char	*tmp;

	iexp = 0;
	if (!ft_is_null(f_str, var.e_start, var.m_end))
	{
		tmp = ft_mul2_traduct(f_str, 0, var.e_end, var);
		iexp = ft_atoi(tmp) - var.e_bias;
		ft_strdel(&tmp);
		if (iexp == -var.e_bias)
			iexp++;
	}
	return (iexp);
}

static char		*ft_convert(char *value, int iexp)
{
	int		i;
	char	*tmp;

	if (iexp > 0)
	{
		i = -1;
		while (++i < iexp)
		{
			tmp = value;
			value = ft_strmul(value, "2", ft_strlen(value), 1);
			ft_strdel(&tmp);
		}
	}
	else
	{
		i = 1;
		while (--i > iexp)
		{
			value = ft_strdivby2(value, ft_strlen(value));
		}
	}
	return (value);
}

char			*ft_get_fvalue(t_option opt, char f_str[], t_define var)
{
	int		iexp;
	char	hidden_bit;
	char	*value;
	int		dot_pos;
	int		len;

	iexp = ft_fill_iexp(f_str, var);
	hidden_bit = ft_fill_hidbit(var, f_str, iexp);
	len = var.m_end;
	value = ft_newtrad(f_str, var.m_start, -1, len);
	value[0] = hidden_bit;
	if (var.buf == LDB_BUF)
		iexp++;
	value = ft_convert(value, iexp);
	if (var.buf == LDB_BUF)
		dot_pos = ft_dbl_len(var.b);
	else
		dot_pos = ft_dbl_len(var.a);
	value = ft_putdot(value, ft_strlen(value), dot_pos);
	value = ft_cut_mantissa(opt, value);
	if (f_str[0] == '1')
		value = ft_charcat('-', value, ft_strlen(value));
	return (value);
}
