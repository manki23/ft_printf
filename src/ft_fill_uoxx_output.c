/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_uoxx_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:25:07 by manki             #+#    #+#             */
/*   Updated: 2019/07/31 11:47:48 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void			ft_prefix(char **nb, t_option opt, unsigned long long arg)
{
	int		nb_len;

	nb_len = ft_strlen(nb[0]);
	if ((opt.option & HASH) && (opt.flag & L_O) && opt.precision
			<= ft_unblen_base(arg, ft_what_base(opt)) && (arg ||
				(!opt.precision && (opt.option & POINT) && !arg)))
		nb[0] = ft_charcat('0', nb[0], nb_len);
	else if ((opt.option & HASH) && (opt.flag & LL_X) && arg)
		nb[0] = ft_bischarcat('0', 'x', nb[0], nb_len);
	else if ((opt.option & HASH) && (opt.flag & LD_X) && arg)
		nb[0] = ft_bischarcat('0', 'X', nb[0], nb_len);
}

static char			*ft_fill_nb(t_option opt, int len, unsigned long long arg)
{
	char	*zero;
	char	*nb;
	char	*base;
	char	*tmp;

	base = ft_what_base(opt);
	if (len > 0)
	{
		nb = ft_ulltoa_base(arg, base);
		zero = (char *)ft_memalloc(opt.precision + 1);
		ft_memset(zero, '0', len);
		tmp = nb;
		nb = ft_strcat(zero, nb);
		ft_strdel(&tmp);
	}
	else if (arg == 0 && (opt.option & POINT) && !opt.precision)
		nb = ft_memalloc(2);
	else
		nb = ft_ulltoa_base(arg, base);
	ft_prefix(&nb, opt, arg);
	return (nb);
}

static void			ft_savelines(t_option op, char **nb, int len, char **output)
{
	char	*tmp;

	tmp = *nb;
	if (op.option & MINUS)
	{
		tmp = *output;
		output[0] = ft_strcat(nb[0], output[0]);
	}
	else if ((op.option & HASH) && (op.option & ZERO) &&
			!(op.option & POINT) && len > 2 &&
			!(op.flag & L_O) && !(op.flag & HH_U))
	{
		output[0] = ft_strcat(output[0], &nb[0][2]);
		nb[0][2] = '\0';
		tmp = output[0];
		output[0] = ft_strcat(nb[0], output[0]);
	}
	else
		output[0] = ft_strcat(output[0], nb[0]);
	ft_strdel(&tmp);
}

static char			*ft_fill_output(t_option op, char *nb)
{
	char	*output;
	int		nb_len;

	output = nb;
	nb_len = ft_strlen(nb);
	if (op.width > nb_len)
	{
		output = (char *)ft_memalloc(op.width + 1);
		nb = (char *)ft_realloc(nb, op.width + 1);
		ft_memset(output, ' ', op.width - nb_len);
		if (!(op.option & MINUS) && !(op.option & POINT) &&
				(op.option & ZERO))
			ft_tr(output, ' ', '0');
		ft_savelines(op, &nb, nb_len, &output);
	}
	return (output);
}

char				*ft_fill_uoxx_output(t_option opt, va_list *ap, size_t *siz)
{
	unsigned long long	arg;
	char				*output;
	int					len;

	arg = va_arg(*ap, unsigned long long);
	if (opt.modif & L_O)
		arg = (unsigned long)arg;
	else if (opt.modif & HH_U)
		arg = (unsigned char)arg;
	else if (opt.modif & H_POURCENT)
		arg = (unsigned short)arg;
	else if (!(opt.modif & LL_X) && !(opt.modif & L_O))
		arg = (unsigned int)arg;
	len = opt.precision - ft_unblen_base(arg, ft_what_base(opt));
	output = ft_fill_nb(opt, len, arg);
	output = ft_fill_output(opt, output);
	siz[0] = ft_strlen(output);
	if (siz[0] == 0)
		ft_strdel(&output);
	return (output);
}
