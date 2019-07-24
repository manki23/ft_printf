/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_p_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:03:01 by manki             #+#    #+#             */
/*   Updated: 2019/07/22 19:38:48 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_fill_nb(t_option opt, int len, unsigned long long arg)
{
	char	*zero;
	char	*nb;
	char	*base;

	base = "0123456789abcdef";
	if (ft_unblen_base(arg, base) < opt.precision)
	{
		zero = ft_strnew(len);
		ft_memset(zero, '0', len);
		nb = ft_strjoin(zero, ft_ulltoa_base(arg, base));
		ft_strdel(&zero);
	}
	//else if (!arg && (opt.option & POINT) && !opt.precision)
	else if ((arg & EMPT) & (opt.option & POINT) & (opt.precision & EMPT))
		nb = "";
	else
		nb = ft_ulltoa_base(arg, base);
	nb = ft_strjoin("0x", nb);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb)
{
	char	*output;

	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!(opt.option & MINUS) && !(opt.option & POINT) && (opt.option & ZERO))
			ft_tr(output, ' ', '0');
		if (opt.option & MINUS)
			output = ft_strjoin(nb, output);
		else
			output = ft_strjoin(output, nb);
	}
	else
		output = nb;
	return (output);
}

char			*ft_fill_p_output(t_option opt, va_list *ap, size_t *size)
{
	void				*arg;
	char				*output;
	int					len;
	unsigned long long	a;

	(void)opt;
	arg = va_arg(*ap, void *);
	a = (unsigned long long)arg;
	len = opt.precision - ft_unblen_base(a, "0123456789abcdef");
	output = ft_fill_nb(opt, len, a);
	output = ft_fill_output(opt, output);
	size[0] = ft_strlen(output);
	return (output);
}
