/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_uoxx_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:25:07 by manki             #+#    #+#             */
/*   Updated: 2019/07/21 16:46:29 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>
static char			*ft_what_base(t_option opt)
{
	if (opt.flag == 'o')
		return ("01234567");
	else if (opt.flag == 'x')
		return ("0123456789abcdef");
	else if (opt.flag == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0123456789");
}

static char			*ft_fill_nb(t_option opt, int len, unsigned long long arg)
{
	char	*zero;
	char	*nb;
	char	*base;
//	char	*tmp;

	base = ft_what_base(opt);
	if (ft_unblen_base(arg, base) < opt.precision)
	{
		zero = ft_strnew(len);
		ft_memset(zero, '0', len);
		nb = ft_strjoin(zero, ft_ulltoa_base(arg, base));
		ft_strdel(&zero);
	}
	else if (arg == 0 && opt.point && !opt.precision)
		nb = "";
	else
		nb = ft_ulltoa_base(arg, base);
//	tmp = nb;
	if (opt.hashtag && opt.flag == 'o' && opt.precision <=
			ft_unblen_base(arg, base) && (arg || (!opt.precision && opt.point
					&& !arg)))
		nb = ft_strjoin("0", nb);
	else if (opt.hashtag && opt.flag == 'x' && arg)
		nb = ft_strjoin("0x", nb);
	else if (opt.hashtag && opt.flag == 'X' && arg)
		nb = ft_strjoin("0X", nb);
//	if (opt.hashtag && ((opt.flag == 'o' && opt.precision <=
//				ft_unblen_base(arg, base) && (arg || (!opt.precision &&
//						opt.point && !arg))) || (opt.flag == 'x' && arg) ||
//				(opt.flag == 'X' && arg)))
//		ft_strdel(&tmp);
	return (nb);
}

static char			*ft_fill_output(t_option opt, char *nb)
{
	char	*output;
	char	*tmp;

	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!opt.minus && !opt.point && opt.zero)
			ft_tr(output, ' ', '0');
		tmp = output;
		if (opt.minus)
			output = ft_strjoin(nb, output);
		else if (opt.hashtag && opt.zero && !opt.point && opt.flag != 'o' &&
				opt.flag != 'u' && ft_strlen(nb) > 2)
		{
			output = ft_strjoin(output, &nb[2]);
			ft_strdel(&tmp);
			tmp = output;
			nb[2] = '\0';
			output = ft_strjoin(nb, output);
		}
		else
			output = ft_strjoin(output, nb);
		ft_strdel(&tmp);
	}
	else
		output = nb;
//	ft_strdel(&nb);
	return (output);
}

static unsigned int	ft_if_short_mod(t_option opt, unsigned long long arg)
{
	if (opt.hh)
		return ((unsigned char)arg);
	else if (opt.h)
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
	if (opt.l)
		arg = (unsigned long)arg;
	else if (!opt.ll && !opt.l)
		arg = ft_if_short_mod(opt, arg);
	len = opt.precision - ft_unblen_base(arg, ft_what_base(opt));
	nb = ft_fill_nb(opt, len, arg);
	output = ft_fill_output(opt, nb);
	siz[0] = ft_strlen(output);
	return (output);
}
