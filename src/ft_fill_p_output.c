/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_p_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:03:01 by manki             #+#    #+#             */
/*   Updated: 2019/07/27 15:55:41 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_fill_nb(t_option opt, int len, unsigned long long arg)
{
	char	*zero;
	char	*nb;
	char	*base;
	char	*tmp;

	base = "0123456789abcdef";
	if (ft_unblen_base(arg, base) < opt.precision)
	{
		nb = ft_ulltoa_base(arg, base);
		zero = ft_memalloc(ft_strlen(nb) + len + 1);
		ft_memset(zero, '0', len);
		tmp = nb;
		nb = ft_strcat(zero, nb);
		ft_strdel(&tmp);
	}
	else if ((arg == 0) && (opt.option & POINT) && (opt.precision == 0))
		nb = ft_memalloc(2);
	else
		nb = ft_ulltoa_base(arg, base);
	nb = ft_charcat('x', nb, ft_strlen(nb));
	nb = ft_charcat('0', nb, ft_strlen(nb));
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb)
{
	char	*output;
	char	*tmp;

	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_memalloc(opt.width + 1);
		nb = ft_realloc(nb, opt.width + 1);
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!(opt.option & MINUS) && !(opt.option & POINT) &&
				(opt.option & ZERO))
			ft_tr(output, ' ', '0');
		if (opt.option & MINUS)
		{
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

	arg = va_arg(*ap, void *);
	a = (unsigned long long)arg;
	len = opt.precision - ft_unblen_base(a, "0123456789abcdef");
	output = ft_fill_nb(opt, len, a);
	output = ft_fill_output(opt, output);
	size[0] = ft_strlen(output);
	return (output);
}
