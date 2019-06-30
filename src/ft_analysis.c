/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:57:23 by manki             #+#    #+#             */
/*   Updated: 2019/06/30 16:05:02 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_conv	g_tab[] =
{
	{"d", &ft_fill_di_output},
	{"i", &ft_fill_di_output},
	{"o", &ft_fill_o_output},
	{"u", &ft_fill_u_output},
	{"x", &ft_fill_x_output},
	{"X", &ft_fill_x_output},
	{"%", &ft_fill_pourcent_output},
	{"c", &ft_fill_c_output},
	{"s", &ft_fill_s_output},
	{"p", &ft_fill_p_output},
	{"f", &ft_fill_f_output}
};

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

int		ft_is_conv(char c)
{
	int		i;

	i = -1;
	while (++i < 11)
	{
		if (c == (g_tab + i)->c[0])
			return(1);
	}
	return (0);
}

void	ft_fill_t_option(t_option *opt, char **p)
{
	p[0]++;
	while (p[0][0] && !ft_is_conv(p[0][0]))
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

char	*ft_conv(char **p, va_list *ap)
{
	t_option	opt;
	char		*output;
	int			i;

	while (p[0][0])
	{
		ft_init_option(&opt);
		ft_fill_t_option(&opt, p);
		i = -1;
		while (g_tab + ++i)
		{
			if (p[0][0] == (g_tab + i)->c[0])
			{
				output = (g_tab + i)->fun(opt, ap);
				p[0]++;
				return (output);
			}
		}
		return ("Error\n");
	}
	return (NULL);
}
