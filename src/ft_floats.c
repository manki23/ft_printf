/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:11:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/27 14:15:11 by manki            ###   ########.fr       */
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
	{
		nb = ft_memalloc(ft_strlen(f_str) + 1);
		nb = ft_strncpy(nb, f_str, ft_strlen(f_str));
	}
	else
	{
		nb = ft_get_fvalue(opt, f_str, *var);
		nul = ft_is_null(f_str, 0, ft_strlen(f_str) - 1);
	}
	if ((opt.option & PLUS) && ((f_str[0] == '0' || (nul == 1)) || ((nul == 2)
					&& (nb[0] != '-') && (nb[0] != 'n'))))
		nb = ft_charcat('+', nb, ft_strlen(nb));
	else if ((opt.option & SPACE) && ((f_str[0] == '0' || (nul == 1)) ||
				((nul == 2) && (nb[0] != '-') && (nb[0] != 'n'))))
		nb = ft_charcat(' ', nb, ft_strlen(nb));
	ft_strdel(&f_str);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb)
{
	char	*output;
	char	*tmp;

	output = nb;
	if (opt.width > (int)ft_strlen(nb))
	{
		output = (char *)ft_memalloc(opt.width + 1);
		nb = (char *)ft_realloc(nb, opt.width + 1);
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!(opt.option & MINUS) && (opt.option & ZERO) &&
				(ft_isdigit(nb[0]) || ft_isdigit(nb[1])))
			ft_tr(output, ' ', '0');
		if (opt.option & MINUS)
		{
			tmp = output;
			output = ft_strcat(nb, output);
			ft_strdel(&tmp);
		}
		else if (((((opt.option & PLUS) || (opt.option & SPACE)) &&
						(nb[0] != '-') && (opt.option & ZERO)) ||
					((opt.option & ZERO) && (nb[0] == '-'))) &&
				(ft_isdigit(nb[0]) || ft_isdigit(nb[1])))
		{
			output = ft_strcat(output, &nb[1]);
			nb[1] = '\0';
			tmp = output;
			output = ft_strcat(nb, output);
			ft_strdel(&tmp);
		}
		else
		{
			tmp = nb;
			output = ft_strcat(output, nb);
			ft_strdel(&tmp);
		}
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
