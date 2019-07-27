/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_di_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:21:52 by manki             #+#    #+#             */
/*   Updated: 2019/07/27 12:59:11 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_fill_nb(t_option opt, int len, long long arg)
{
	char	*zero;
	char	*nb;
	char	*tmp;

	if (ft_nblen(arg) < opt.precision)
	{
		nb = ft_lltoa(arg);
		zero = (char *)ft_memalloc(ft_strlen(nb) + len + 2);
		ft_memset(zero, '0', len);
		tmp = nb;
		nb = ft_strcat(zero, nb);
		ft_strdel(&tmp);
		if (arg < 0)
		{
			nb[0] = '-';
			nb[len] = '0';
		}
	}
	else if (arg == 0 && (opt.option & POINT) && !opt.precision)
		nb = ft_memalloc(2);
	else
		nb = ft_realloc(ft_lltoa(arg), ft_nblen(arg) + 2);
	if ((opt.option & PLUS) && arg >= 0)
		nb = ft_charcat('+', nb, ft_strlen(nb));
	else if ((opt.option & SPACE) && arg >= 0)
		nb = ft_charcat(' ', nb, ft_strlen(nb));
	return (nb);
}

static char		*ft_fill_output(t_option o, char *nb, long long arg)
{
	char	*output;
	char	*tmp;

	output = nb;
	if (o.width > (int)ft_strlen(nb))
	{
		output = (char *)ft_memalloc(o.width + 1);
		nb = (char *)ft_realloc(nb, o.width + 1);
		ft_memset(output, ' ', o.width - ft_strlen(nb));
		if (!(o.option & MINUS) && !(o.option & POINT) && (o.option & ZERO))
			ft_tr(output, ' ', '0');
		if (o.option & MINUS)
		{
			tmp = output;
			output = ft_strcat(nb, output);
			ft_strdel(&tmp);
		}
		else if ((((o.option & PLUS) || (o.option & SPACE)) && arg >= 0 &&
					(o.option & ZERO) && !(o.option & POINT)) ||
				(!(o.option & POINT) && (o.option & ZERO) && arg < 0))
		{
			output = ft_strcat(output, &nb[1]);
			nb[1] = '\0';
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

static int		ft_if_short_mod(t_option opt, int arg)
{
	if (ft_read(&(opt.modif), 1))
		return ((char)arg);
	else if (ft_read(&(opt.modif), 0))
		return ((short)arg);
	else
		return (arg);
}

char			*ft_fill_di_output(t_option opt, va_list *ap, size_t *size)
{
	char		*output;
	char		*nb;
	int			len;
	long long	arg;

	arg = va_arg(*ap, long long);
	if (ft_read(&(opt.modif), 2))
		arg = (long)arg;
	else if (!ft_read(&(opt.modif), 3) && !ft_read(&(opt.modif), 2))
		arg = ft_if_short_mod(opt, arg);
	len = opt.precision - ft_nblen(arg);
	nb = ft_fill_nb(opt, len, arg);
	output = ft_fill_output(opt, nb, arg);
	size[0] = ft_strlen(output);
	return (output);
}
