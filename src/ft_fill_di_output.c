/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_di_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:21:52 by manki             #+#    #+#             */
/*   Updated: 2019/07/22 15:39:09 by manki            ###   ########.fr       */
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
		zero = ft_strnew(len);
		ft_memset(zero, '0', len);
		nb = ft_lltoa(arg);
		if (arg < 0)
		{
			tmp = nb;
			nb = ft_strjoin(zero, &nb[1]);
			zero[0] = '-';
			zero[1] = '\0';
			ft_strdel(&tmp);
		}
		tmp = nb;
		nb = ft_strjoin(zero, nb);
		ft_strdel(&tmp);
		ft_strdel(&zero);
	}
	else if (arg == 0 && ft_read(&(opt.option), 5) && !opt.precision)
		nb = "";
	else
		nb = ft_lltoa(arg);
	if (ft_read(&(opt.option), 1) && arg >= 0)
		nb = ft_strjoin("+", nb);
	else if (ft_read(&(opt.option), 3) && arg >= 0)
		nb = ft_strjoin(" ", nb);
	return (nb);
}

static char		*ft_fill_output(t_option opt, char *nb, long long arg)
{
	char	*output;
///	char	*tmp;

	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!ft_read(&(opt.option), 0) && !ft_read(&(opt.option), 5) &&
				ft_read(&(opt.option), 2))
			ft_tr(output, ' ', '0');
///		tmp = output;
		if (ft_read(&(opt.option), 0))
			output = ft_strjoin(nb, output);
		else if (((ft_read(&(opt.option), 1) || ft_read(&(opt.option), 3)) &&
					arg >= 0 && ft_read(&(opt.option), 2) && 
					!ft_read(&(opt.option), 5)) || (!ft_read(&(opt.option), 5)
					&& ft_read(&(opt.option), 2) && arg < 0))
		{
			output = ft_strjoin(output, &nb[1]);
///			ft_strdel(&tmp);
///			tmp = output;
			nb[1] = '\0';
			output = ft_strjoin(nb, output);
		}
		else
			output = ft_strjoin(output, nb);
///		ft_strdel(&tmp);
	}
	else
		output = nb;
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
