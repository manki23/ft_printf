/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_uoxx_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:25:07 by manki             #+#    #+#             */
/*   Updated: 2019/07/25 02:49:32 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char			*ft_what_base(t_option opt)
{
	if (opt.flag & L_o)
		return ("01234567");
	else if (opt.flag & LL_x)
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

	base = ft_what_base(opt);
	if (ft_unblen_base(arg, base) < opt.precision)
	{
		zero = ft_strnew(len);
		ft_memset(zero, '0', len);
		nb = ft_strjoin(zero, ft_ulltoa_base(arg, base));
		ft_strdel(&zero);
	}
	else if (arg == 0 && (opt.option & POINT) && !opt.precision)
		nb = "";
	else
		nb = ft_ulltoa_base(arg, base);
	if ((opt.option & HASH) && (opt.flag & L_o) && opt.precision
			<= ft_unblen_base(arg, base) && (arg || (!opt.precision &&
					(opt.option & POINT) && !arg)))
		nb = ft_strjoin("0", nb);
	else if ((opt.option & HASH) && (opt.flag & LL_x) && arg)
		nb = ft_strjoin("0x", nb);
	else if ((opt.option & HASH) && (opt.flag & LD_X) && arg)
		nb = ft_strjoin("0X", nb);
	return (nb);
}

static char			*ft_fill_output(t_option opt, char *nb)
{
	char	*output;

	output = nb;
	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!(opt.option & MINUS) && !(opt.option & POINT) &&
				(opt.option & ZERO))
			ft_tr(output, ' ', '0');
		if (opt.option & MINUS)
			output = ft_strjoin(nb, output);
		else if ((opt.option & HASH) && (opt.option & ZERO) &&
				!(opt.option & POINT) && ft_strlen(nb) > 2 &&
				!(opt.flag & L_o) && !(opt.flag & HH_u))
		{
			output = ft_strjoin(output, &nb[2]);
			nb[2] = '\0';
			output = ft_strjoin(nb, output);
		}
		else
			output = ft_strjoin(output, nb);
	}
	return (output);
}

static unsigned int	ft_if_short_mod(t_option opt, unsigned long long arg)
{
	if (opt.modif & HH_u)
		return ((unsigned char)arg);
	else if (opt.modif & H_pourcent)
		return ((unsigned short)arg);
	else
		return (arg);
}

char				*ft_fill_uoxx_output(t_option opt, va_list *ap, size_t *siz)
{
	unsigned long long	arg;
	char				*output;
	char				*nb;
	int					len;

	arg = va_arg(*ap, unsigned long long);
	if (opt.modif & L_o)
		arg = (unsigned long)arg;
	else if (!(opt.modif & LL_x) && !(opt.modif & L_o))
		arg = ft_if_short_mod(opt, arg);
	len = opt.precision - ft_unblen_base(arg, ft_what_base(opt));
	nb = ft_fill_nb(opt, len, arg);
	output = ft_fill_output(opt, nb);
	siz[0] = ft_strlen(output);
	return (output);
}
