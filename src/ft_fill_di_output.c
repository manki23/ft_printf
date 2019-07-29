/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_di_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:21:52 by manki             #+#    #+#             */
/*   Updated: 2019/07/29 16:36:12 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_prefix(t_option opt, char **nb, long long arg)
{
	if ((opt.option & PLUS) && arg >= 0)
		nb[0] = ft_charcat('+', nb[0], ft_strlen(nb[0]));
	else if ((opt.option & SPACE) && arg >= 0)
		nb[0] = ft_charcat(' ', nb[0], ft_strlen(nb[0]));
}

static char		*ft_fill_nb(t_option opt, int len, long long arg)
{
	char	*zero;
	char	*nb;
	char	*tmp;

	if (len > 0)
	{
		nb = ft_lltoa(arg);
		zero = (char *)ft_memalloc(opt.precision + 2);
		ft_memset(zero, '0', len);
		tmp = nb;
		nb = ft_strcat(zero, nb);
		ft_strdel(&tmp);
		if (arg < 0)
			nb[0] = '-';
		if (arg < 0)
			nb[len] = '0';
	}
	else if (!(arg == 0 && (opt.option & POINT) && !opt.precision))
		nb = ft_realloc(ft_lltoa(arg), opt.precision - len + 2);
	else
		nb = ft_memalloc(2);
	ft_prefix(opt, &nb, arg);
	return (nb);
}

static void		ft_savelines(t_option o, char **nb, long long a, char **output)
{
	char	*tmp;

	tmp = nb[0];
	if (o.option & MINUS)
	{
		tmp = output[0];
		output[0] = ft_strcat(nb[0], output[0]);
	}
	else if ((((o.option & PLUS) || (o.option & SPACE)) && a >= 0 &&
				(o.option & ZERO) && !(o.option & POINT)) ||
			(!(o.option & POINT) && (o.option & ZERO) && a < 0))
	{
		output[0] = ft_strcat(output[0], &nb[0][1]);
		nb[0][1] = '\0';
		tmp = output[0];
		output[0] = ft_strcat(nb[0], output[0]);
	}
	else
		output[0] = ft_strcat(output[0], nb[0]);
	ft_strdel(&tmp);
}

static char		*ft_fill_output(t_option o, char *nb, long long arg)
{
	char	*output;
	int		nb_len;

	output = nb;
	nb_len = ft_strlen(nb);
	if (o.width > nb_len)
	{
		output = (char *)ft_memalloc(o.width + 1);
		nb = (char *)ft_realloc(nb, o.width + 1);
		ft_memset(output, ' ', o.width - nb_len);
		if (!(o.option & MINUS) && !(o.option & POINT) && (o.option & ZERO))
			ft_tr(output, ' ', '0');
		ft_savelines(o, &nb, arg, &output);
	}
	return (output);
}

char			*ft_fill_di_output(t_option opt, va_list *ap, size_t *size)
{
	char		*output;
	char		*nb;
	int			len;
	long long	arg;

	arg = va_arg(*ap, long long);
	if (opt.modif & L_O)
		arg = (long)arg;
	else if (opt.modif & HH_U)
		arg = (char)arg;
	else if (opt.modif & H_POURCENT)
		arg = (short)arg;
	else if (!(opt.modif & LL_X) && !(opt.modif & L_O))
		arg = (int)arg;
	len = opt.precision - ft_dbl_len(arg);
	nb = ft_fill_nb(opt, len, arg);
	output = ft_fill_output(opt, nb, arg);
	size[0] = ft_strlen(output);
	return (output);
}
