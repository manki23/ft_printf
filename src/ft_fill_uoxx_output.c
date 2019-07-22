/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_uoxx_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:25:07 by manki             #+#    #+#             */
/*   Updated: 2019/07/22 17:12:51 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

#include <stdio.h>
static char			*ft_what_base(t_option opt)
{
	if (ft_read(&(opt.flag), 2))
		return ("01234567");
	else if (ft_read(&(opt.flag), 3))
		return ("0123456789abcdef");
	else if (ft_read(&(opt.flag), 4))
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
	else if (arg == 0 && ft_read(&(opt.option), 5) && !opt.precision)
		nb = "";
	else
		nb = ft_ulltoa_base(arg, base);
	if (ft_read(&(opt.option), 4) && ft_read(&(opt.flag), 2) && opt.precision
			<= ft_unblen_base(arg, base) && (arg || (!opt.precision &&
					ft_read(&(opt.option), 5) && !arg)))
		nb = ft_strjoin("0", nb);
	else if (ft_read(&(opt.option), 4) && ft_read(&(opt.flag), 3) && arg)
		nb = ft_strjoin("0x", nb);
	else if (ft_read(&(opt.option), 4) && ft_read(&(opt.flag), 4) && arg)
		nb = ft_strjoin("0X", nb);
	return (nb);
}

static char			*ft_fill_output(t_option opt, char *nb)
{
	char	*output;

	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!ft_read(&(opt.option), 0) && !ft_read(&(opt.option), 5) &&
				ft_read(&(opt.option), 2))
			ft_tr(output, ' ', '0');
		if (ft_read(&(opt.option), 0))
			output = ft_strjoin(nb, output);
		else if (ft_read(&(opt.option), 4) && ft_read(&(opt.option), 2) &&
				!ft_read(&(opt.option), 5) && ft_strlen(nb) > 2 &&
				!ft_read(&(opt.flag), 2) && !ft_read(&(opt.flag), 1))
		{
			output = ft_strjoin(output, &nb[2]);
			nb[2] = '\0';
			output = ft_strjoin(nb, output);
		}
		else
			output = ft_strjoin(output, nb);
	}
	else
		output = nb;
	return (output);
}

static unsigned int	ft_if_short_mod(t_option opt, unsigned long long arg)
{
	if (ft_read(&(opt.modif), 1))
		return ((unsigned char)arg);
	else if (ft_read(&(opt.modif), 0))
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
	if (ft_read(&(opt.modif), 2))
		arg = (unsigned long)arg;
	else if (!ft_read(&(opt.modif), 3) && !ft_read(&(opt.modif), 2))
		arg = ft_if_short_mod(opt, arg);
	len = opt.precision - ft_unblen_base(arg, ft_what_base(opt));
	nb = ft_fill_nb(opt, len, arg);
	output = ft_fill_output(opt, nb);
	siz[0] = ft_strlen(output);
	return (output);
}
