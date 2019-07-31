/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:11:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/31 10:16:23 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_fill_nb(t_option opt, t_define *var)
{
	char	*f_str;
	char	*nb;
	int		nul;

	f_str = ft_dbl_to_str(*var);
	nul = 2;
	if (!ft_strcmp(f_str, "nan") || !ft_strcmp(f_str, "inf") ||
			!ft_strcmp(f_str, "-inf"))
	{
		nb = ft_memalloc(var->m_end + 2);
		nb = ft_strncpy(nb, f_str, var->m_end + 1);
	}
	else
	{
		nb = ft_get_fvalue(opt, f_str, *var);
		nul = ft_is_null(f_str, 0, var->m_end);
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

static void		ft_savelines(t_option opt, char **nb, char **output)
{
	char	*tmp;

	if (opt.option & MINUS)
	{
		tmp = *output;
		output[0] = ft_strcat(nb[0], output[0]);
		ft_strdel(&tmp);
	}
	else if (((((opt.option & PLUS) || (opt.option & SPACE)) &&
					(nb[0][0] != '-') && (opt.option & ZERO)) ||
				((opt.option & ZERO) && (nb[0][0] == '-'))) &&
			(ft_isdigit(nb[0][0]) || ft_isdigit(nb[0][1])))
	{
		output[0] = ft_strcat(output[0], &nb[0][1]);
		nb[0][1] = '\0';
		tmp = *output;
		output[0] = ft_strcat(nb[0], output[0]);
		ft_strdel(&tmp);
	}
	else
	{
		tmp = *nb;
		output[0] = ft_strcat(output[0], nb[0]);
		ft_strdel(&tmp);
	}
}

static char		*ft_fill_output(t_option opt, char *nb)
{
	char	*output;

	output = nb;
	if (opt.width > (int)ft_strlen(nb))
	{
		output = (char *)ft_memalloc(opt.width + 1);
		nb = (char *)ft_realloc(nb, opt.width + 1);
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!(opt.option & MINUS) && (opt.option & ZERO) &&
				(ft_isdigit(nb[0]) || ft_isdigit(nb[1])))
			ft_tr(output, ' ', '0');
		ft_savelines(opt, &nb, &output);
	}
	return (output);
}

char			*ft_fill_f_output(t_option opt, va_list *ap, size_t *size)
{
	double		a;
	char		*output;
	t_define	var;
	long double b;

	if (opt.modif & LD_X)
	{
		b = va_arg(*ap, long double);
		ft_setvar(&var, opt.modif & LD_X, b, (double)b);
	}
	else
	{
		a = va_arg(*ap, double);
		ft_setvar(&var, opt.modif & LD_X, 0, a);
	}
	output = ft_fill_nb(opt, &var);
	output = ft_fill_output(opt, output);
	size[0] = ft_strlen(output);
	return (output);
}
