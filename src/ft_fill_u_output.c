/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_u_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:09:22 by manki             #+#    #+#             */
/*   Updated: 2019/07/02 20:27:48 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_unsigned_nblen(unsigned long long n)
{
	if (n < 10)
		return (1);
	else
		return (ft_nblen(n / 10) + ft_nblen(n % 10));
}
static char		*ft_fill_nb(t_option opt, int len, unsigned long long arg)
{
	char	*zero;
	char	*nb;

	if (ft_nblen(arg) < opt.precision)
	{
		zero = ft_strnew(len);
		ft_memset(zero, '0', len);
		nb = ft_strjoin(zero, ft_ulltoa(arg));
	}
	else if (arg == 0 && opt.point && !opt.precision)
		nb = "";
	else
		nb = ft_lltoa(arg);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb)
{
	char	*output;

	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!opt.minus && !opt.point && opt.zero)
			ft_tr(output, ' ', '0');
		if (opt.minus)
			output = ft_strjoin(nb, output);
		else
			output = ft_strjoin(output, nb);
	}
	else
		output = nb;
	return (output);
}

/*int				ft_if_short_mod(t_option opt, int arg)
{
	int		mod;

	mod = 0;
	if (opt.hh)
		mod = 256;
	else if (opt.h)
		mod = 65536;
	while ((opt.hh || opt.h) && arg > ((mod / 2) - 1))
		arg -= mod;
	while ((opt.hh || opt.h) && arg < -(mod / 2))
		arg += mod;
	return (arg);
}*/

char			*ft_fill_u_output(t_option opt, va_list *ap)
{
	unsigned long long	arg;
	char				*output;
	char				*nb;
	int					len;

	arg = va_arg(*ap, unsigned long long);
	if (opt.l)
		arg = (unsigned long)arg;
	else if (!opt.ll && !opt.l)
		arg = (unsigned int)arg;
	len = opt.precision - ft_unsigned_nblen(arg);
	nb = ft_fill_nb(opt, len, arg);
	output = ft_fill_output(opt, nb);
	return (output);
}
