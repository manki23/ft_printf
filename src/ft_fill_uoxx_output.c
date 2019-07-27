/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_uoxx_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:25:07 by manki             #+#    #+#             */
/*   Updated: 2019/07/27 15:49:03 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char			*ft_what_base(t_option opt)
{
	if (opt.flag & L_O)
		return ("01234567");
	else if (opt.flag & LL_X)
		return ("0123456789abcdef");
	else if (opt.flag & LD_X)
		return ("0123456789ABCDEF");
	else
		return ("0123456789");
}

static char			*ft_fill_nb(t_option opt, int len, unsigned long long arg)
{
	char	*zero;
	char	*nb;
	char	*base;
	char	*tmp;

	base = ft_what_base(opt);
	if (ft_unblen_base(arg, base) < opt.precision)
	{
		nb = ft_ulltoa_base(arg, base);
		zero = (char *)ft_memalloc(len + ft_strlen(nb) + 1);
		ft_memset(zero, '0', len);
		tmp = nb;
		nb = ft_strcat(zero, nb);
		ft_strdel(&tmp);
	}
	else if (arg == 0 && (opt.option & POINT) && !opt.precision)
		nb = ft_memalloc(2);
	else
		nb = ft_ulltoa_base(arg, base);
	if ((opt.option & HASH) && (opt.flag & L_O) && opt.precision
			<= ft_unblen_base(arg, base) && (arg || (!opt.precision &&
					(opt.option & POINT) && !arg)))
		nb = ft_charcat('0', nb, ft_strlen(nb));
	else if ((opt.option & HASH) && (opt.flag & LL_X) && arg)
	{
		nb = ft_charcat('x', nb, ft_strlen(nb));
		nb = ft_charcat('0', nb, ft_strlen(nb));
	}
	else if ((opt.option & HASH) && (opt.flag & LD_X) && arg)
	{
		nb = ft_charcat('X', nb, ft_strlen(nb));
		nb = ft_charcat('0', nb, ft_strlen(nb));
	}
	return (nb);
}

static char			*ft_fill_output(t_option op, char *nb)
{
	char	*output;
	char	*tmp;

	output = nb;
	if (op.width > (int)ft_strlen(nb))
	{
		output = (char *)ft_memalloc(op.width + 1);
		nb = (char *)ft_realloc(nb, op.width + 1);
		ft_memset(output, ' ', op.width - ft_strlen(nb));
		if (!(op.option & MINUS) && !(op.option & POINT) &&
				(op.option & ZERO))
			ft_tr(output, ' ', '0');
		if (op.option & MINUS)
		{
			tmp = output;
			output = ft_strcat(nb, output);
			ft_strdel(&tmp);
		}
		else if ((op.option & HASH) && (op.option & ZERO) &&
				!(op.option & POINT) && ft_strlen(nb) > 2 &&
				!(op.flag & L_O) && !(op.flag & HH_U))
		{
			output = ft_strcat(output, &nb[2]);
			nb[2] = '\0';
			tmp = output;
			output = ft_strcat(nb, output);
			ft_strdel(&tmp);
		}
		else
		{
			output = ft_strcat(output, nb);
			ft_strdel(&nb);
		}
	}
	return (output);
}

static unsigned int	ft_if_short_mod(t_option opt, unsigned long long arg)
{
	if (opt.modif & HH_U)
		return ((unsigned char)arg);
	else if (opt.modif & H_POURCENT)
		return ((unsigned short)arg);
	else
		return (arg);
}

char				*ft_fill_uoxx_output(t_option opt, va_list *ap, size_t *siz)
{
	unsigned long long	arg;
	char				*output;
	int					len;

	arg = va_arg(*ap, unsigned long long);
	if (opt.modif & L_O)
		arg = (unsigned long)arg;
	else if (!(opt.modif & LL_X) && !(opt.modif & L_O))
		arg = ft_if_short_mod(opt, arg);
	len = opt.precision - ft_unblen_base(arg, ft_what_base(opt));
	output = ft_fill_nb(opt, len, arg);
	output = ft_fill_output(opt, output);
	siz[0] = ft_strlen(output);
	return (output);
}
