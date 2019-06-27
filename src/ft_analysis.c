/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:57:23 by manki             #+#    #+#             */
/*   Updated: 2019/06/27 16:04:43 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_init_option(t_option *opt)
{
	opt->minus = 0;
	opt->plus = 0;
	opt->zero = 0;
	opt->space = 0;
	opt->hashtag = 0;
	opt->point = 0;
	opt->width = 0;
	opt->precision = 0;
}

void	ft_fill_t_option(t_option *opt, char **p)
{
	while (p[0][0] && p[0][0] != 'd' && p[0][0] != 'i')
	{
		if (p[0][0] == '-')
			opt->minus++;
		else if (p[0][0] == '+')
			opt->plus++;
		else if (p[0][0] == '0')
			opt->zero++;
		else if (p[0][0] == ' ')
			opt->space++;
		else if (p[0][0] == '#')
			opt->hashtag++;
		else if (!opt->point && ft_isdigit(p[0][0]))
		{
			opt->width = ft_atoi(p[0]);
			p[0] += ft_nblen(ft_atoi(p[0])) - 1;
		}
		else if (p[0][0] == '.')
			opt->point++;
		else if (opt->point && ft_isdigit(p[0][0]))
		{
			opt->precision = ft_atoi(p[0]);
			p[0] += ft_nblen(ft_atoi(p[0])) - 1;
		}
		p[0]++;
	}
}

char	*ft_fill_di_output(t_option opt, int arg)
{
	char	*output;
	char	*nb;
	char	*zero;
	int		len;

	len = opt.precision - ft_nblen(arg);
	if (ft_nblen(arg) < opt.precision)
	{
		zero = ft_strnew(len);
		ft_memset(zero, '0', len);
		nb = ft_itoa(arg);
		if (arg < 0)
		{
			nb = ft_strjoin(zero, &nb[1]);
			zero[0] = '-';
			zero[1] = '\0';
		}
		nb = ft_strjoin(zero, nb);
	}
	else if (arg == 0 && opt.point && !opt.precision)
		nb = "";
	else
		nb = ft_itoa(arg);
	if (opt.plus && arg >= 0)
		nb = ft_strjoin("+", nb);
	else if (opt.space && arg >= 0)
		nb = ft_strjoin(" ", nb);
	if (opt.width > (int)ft_strlen(nb))
	{
		output = ft_strnew(opt.width - ft_strlen(nb));
		ft_memset(output, ' ', opt.width - ft_strlen(nb));
		if (!opt.minus && !opt.point && opt.zero)
			ft_tr(output, ' ', '0');
		if (opt.minus)
			output = ft_strjoin(nb, output);
		else if (((opt.plus || opt.space) && arg >= 0 && opt.zero && !opt.minus
					&& !opt.point) || (!opt.minus && !opt.point && opt.zero &&
						arg < 0))
		{
			output = ft_strjoin(output, &nb[1]);
			nb[1] = '\0';
			output = ft_strjoin(nb, output);
		}
		else
			output = ft_strjoin(output, nb);
	}
	else
		output = nb;
	return (output);
}

char	*ft_conv(char **p, va_list *ap)
{
	t_option	opt;
	char		*output;

	while (p[0][0])
	{
		ft_init_option(&opt);
		ft_fill_t_option(&opt, p);
		if (p[0][0] == 'd' || p[0][0] == 'i')
		{
			output = ft_fill_di_output(opt, va_arg(*ap, int));
			p[0]++;
			return (output);
		}
		return ("not done yet!\n");
	}
	return (NULL);
}
