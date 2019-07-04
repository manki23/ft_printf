/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:05:23 by manki             #+#    #+#             */
/*   Updated: 2019/07/04 14:16:41 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_init_option(t_option *opt)
{
	opt->flag = '\0';
	opt->minus = 0;
	opt->plus = 0;
	opt->zero = 0;
	opt->space = 0;
	opt->hashtag = 0;
	opt->point = 0;
	opt->width = 0;
	opt->precision = 0;
	opt->hh = 0;
	opt->h = 0;
	opt->l = 0;
	opt->ll = 0;
	opt->ld = 0;
}

static int		ft_fill_length_mod(t_option *opt, char **p)
{
	int		inc;

	inc = 0;
	if (p[0][0] == 'h' && p[0][1] == 'h' && (inc = 2))
		opt->hh += 1;
	else if (p[0][0] == 'h' && p[0][1] != 'h' && (inc = 1))
		opt->h += 1;
	else if (p[0][0] == 'l' && p[0][1] == 'l' && (inc = 2))
		opt->ll += 1;
	else if (p[0][0] == 'l' && p[0][1] != 'l' && (inc = 1))
		opt->l += 1;
	else if (p[0][0] == 'L' && (inc = 1))
		opt->ld += 1;
	p[0] += inc;
	return (1);
}

static void		ft_(t_option *opt, char **p)
{
	if (!opt->point && ft_isdigit(p[0][0]))
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
}

void			ft_fill_t_option(t_option *opt, char **p)
{
	while ((++p[0])[0] && ft_fill_length_mod(opt, p) && !ft_is_conv(p[0][0]))
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
		else
			ft_(opt, p);
	}
	opt->flag = p[0][0];
}
