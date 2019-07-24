/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:11:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/24 22:45:16 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_cut_mantissa(t_option opt, char *nb)
{
	int		precision;
	int		i;
	int		j;

	precision = 6;
	if ((opt.option & POINT) && (opt.precision != 6 && opt.precision >= 0))
		precision = opt.precision;
	i = -1;
	j = -1;
	while (j == -1 && nb[++i])
		if (nb[i] == '.')
			j = i;
	while (nb[i] && ((i - j) < precision))
	{
		i++;
	}
	if (nb[i] && ((i - j) == precision))
		nb = ft_roundd(nb, i, &j, precision);
	else if (nb[i] == '\0' && ((i - j) < precision))
	{
		nb = ft_realloc(nb, precision + j + 2);
		while (i <= (precision + j))
		{
			nb[i] = '0';
			i++;
		}
	}
	if (precision == 0 && !(opt.option & HASH))
		nb[j] = '\0';
	return (nb);
}
/*
	ft_putstr("[");
	ft_putstr(nb);
	ft_putstr("]");
	*/

/*static int		ft_firstoneat(char f_str[])
{
	int		i;

	i = 0;
	while (f_str[i + M_START])
	{
		if (f_str[i + M_START] == '1')
			return (i);
		i++;
	}
	return (i);
}*/

static char		*ft_get_value(t_option opt, char f_str[], double arg)
{
	int					iexp;
	int					zero;
	char				hidden_bit;
	char				*value;
	int					i;
	int					dot_pos;


	zero = ft_is_null(f_str, E_START, ft_strlen(f_str) - 1);
	iexp = 0;
	hidden_bit = '0';
	if (!zero)
	{
		iexp = ft_atoi(ft_mul2_traduct(f_str, 0, E_END)) - E_BIAS;
		if (iexp == -1023)
			iexp++;;
	}
	else
		iexp = 0;
	if (!iexp  && !ft_is_null(f_str, M_START, M_END) && f_str[0] != '1')
		iexp = 1 - E_BIAS;
	if ((!ft_is_null(f_str, M_START, M_END)) ||
			(ft_is_null(f_str, M_START, M_END) && !zero))
		hidden_bit = '1';
		if (iexp == -1022)
			hidden_bit = '0';

	value = ft_newtrad(f_str, M_START);
	value[0] = hidden_bit;
//	if (iexp == -1022 && !zero)
//		iexp -= ft_firstoneat(f_str);
//	else if (iexp < -1023 && !zero)
//		iexp += ft_firstoneat(f_str);
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
		{
			value = ft_strdivby2(value, ft_strlen(value));
		}
	}
	dot_pos = ft_dbl_len(arg);
	value = ft_putdot(value, ft_strlen(value), dot_pos);
	value = ft_cut_mantissa(opt, value);
	if (f_str[0] == '1')
		value = ft_charcat('-', value, ft_strlen(value));
	return (value);
}
/*
		ft_putstr("{");
		ft_putstr(ft_lltoa(ft_firstoneat(f_str)));
		ft_putstr("}\n");
		ft_putstr("[");
		ft_putstr(value);
		ft_putstr("]\n");
//		ft_afficher(f_str, 8);
		ft_putstr("[");
		ft_putstr(ft_lltoa(iexp));
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
