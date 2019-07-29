/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_p_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:03:01 by manki             #+#    #+#             */
/*   Updated: 2019/07/29 13:59:19 by manki            ###   ########.fr       */
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
	if (len > 0)
	{
		nb = ft_ulltoa_base(arg, base);
		zero = ft_memalloc(opt.precision + 1);
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
	int		nb_len;

	output = nb;
	nb_len = ft_strlen(nb);
	if (opt.width > nb_len)
	{
		output = ft_memalloc(opt.width + 1);
		nb = ft_realloc(nb, opt.width + 1);
		ft_memset(output, ' ', opt.width - nb_len);
		if (!(opt.option & MINUS) && !(opt.option & POINT) &&
				(opt.option & ZERO))
			ft_tr(output, ' ', '0');
		tmp = nb;
		if (opt.option & MINUS)
		{
			tmp = output;
			output = ft_strcat(nb, output);
		}
		else
			output = ft_strcat(output, nb);
		ft_strdel(&tmp);
	}
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
