/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 02:21:18 by manki             #+#    #+#             */
/*   Updated: 2019/07/25 02:47:17 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_setvar(t_define *var, int ldb, long double b, double a)
{
	if (ldb)
	{
		var->e_start = LDB_E_START;
		var->e_end = LDB_E_END;
		var->m_start = LDB_M_START;
		var->m_end = LDB_M_END;
		var->e_bias = LDB_E_BIAS;
		var->buf = LDB_BUF;
		var->b = b;
		var->a = a;
	}
	else
	{
		var->e_start = E_START;
		var->e_end = E_END;
		var->m_start = M_START;
		var->m_end = M_END;
		var->e_bias = E_BIAS;
		var->buf = BUF;
		var->a = a;
	}
}

static char		ft_fill_hidbit(t_define var, char f_str[], int iexp)
{
	char	hidden_bit;

	hidden_bit = '0';
	if ((!ft_is_null(f_str, var.m_start, var.m_end)) ||
			!ft_is_null(f_str, var.e_start, ft_strlen(f_str) - 1))
		hidden_bit = '1';
	if (iexp == 1 - var.e_bias)
		hidden_bit = '0';
	return (hidden_bit);
}

static int		ft_fill_iexp(char f_str[], t_define var)
{
	int		iexp;

	iexp = 0;
	if (!ft_is_null(f_str, var.e_start, ft_strlen(f_str) - 1))
	{
		iexp = ft_atoi(ft_mul2_traduct(f_str, 0, var.e_end, var)) - var.e_bias;
		if (iexp == -var.e_bias)
			iexp++;
	}
	return (iexp);
}

static char		*ft_convert(char *value, int iexp)
{
	int		i;

	if (iexp > 0)
	{
		i = -1;
		while (++i < iexp)
			value = ft_strmul(value, "2", ft_strlen(value), 1);
	}
	else
	{
		i = 1;
		while (--i > iexp)
			value = ft_strdivby2(value, ft_strlen(value));
	}
	return (value);
}

char			*ft_get_fvalue(t_option opt, char f_str[], t_define var)
{
	int		iexp;
	char	hidden_bit;
	char	*value;
	int		dot_pos;

	iexp = ft_fill_iexp(f_str, var);
	hidden_bit = ft_fill_hidbit(var, f_str, iexp);
	value = ft_newtrad(f_str, var.m_start, -1);
	value[0] = hidden_bit;
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
