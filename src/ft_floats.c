/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:11:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/25 03:02:24 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char			*ft_cut_mantissa(t_option opt, char *nb)
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
		i++;
	if (nb[i] && ((i - j) == precision))
		nb = ft_roundd(nb, i, &j, precision);
	else if (nb[i] == '\0' && ((i - j) < precision))
	{
		nb = ft_realloc(nb, precision + j + 2);
		while (++i - 1 <= (precision + j))
			nb[i - 1] = '0';
	}
	if (precision == 0 && !(opt.option & HASH))
		nb[j] = '\0';
	return (nb);
}

static char		*ft_fill_nb(t_option opt, t_define *var)
{
	char	*f_str;
	char	*nb;
	int		nul;

	if (var->buf == LDB_BUF)
		f_str = ft_ldb_to_str(var->b, var);
	else
		f_str = ft_dbl_to_str(var->a, *var);
	nul = 2;
	if (!ft_strcmp(f_str, "nan") || !ft_strcmp(f_str, "inf") ||
			!ft_strcmp(f_str, "-inf"))
		nb = f_str;
	else
	{
		nb = ft_get_fvalue(opt, f_str, *var);
		nul = ft_is_null(f_str, 0, ft_strlen(f_str) - 1);
	}
	if ((opt.option & PLUS) && ((f_str[0] == '0' || (nul == 1)) || ((nul == 2)
					&& (nb[0] != '-') && (nb[0] != 'n'))))
		nb = ft_strjoin("+", nb);
	else if ((opt.option & SPACE) && ((f_str[0] == '0' || (nul == 1)) ||
				((nul == 2) && (nb[0] != '-') && (nb[0] != 'n'))))
		nb = ft_strjoin(" ", nb);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb)
{
	char	*output;

	output = nb;
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
	return (output);
}

char			*ft_fill_f_output(t_option opt, va_list *ap, size_t *size)
{
	double		a;
	char		*output;
	t_define	var;

/*	long double b;
	if (opt.modif & LD_X)
	{
		b = va_arg(*ap, long double);
		ft_setvar(&var, opt.modif & LD_X, b, (double)b);
		output = ft_fill_nb(opt, &var);
		output = ft_fill_output(opt, output);
		size[0] = ft_strlen(output);
		return (output);
	}
*/
	a = va_arg(*ap, double);
	ft_setvar(&var, opt.modif & LD_X, 0, a);
	output = ft_fill_nb(opt, &var);
	output = ft_fill_output(opt, output);
	size[0] = ft_strlen(output);
	return (output);
}
