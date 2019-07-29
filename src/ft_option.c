/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:05:23 by manki             #+#    #+#             */
/*   Updated: 2019/07/29 16:39:50 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_init_option(t_option *opt)
{
	opt->flag = 0;
	opt->option = 0;
	opt->modif = 0;
	opt->width = 0;
	opt->precision = 0;
}

static int		ft_fill_length_mod(t_option *opt, char **p)
{
	int		ret;

	ret = 0;
	if (ft_read(&(opt->modif), 0) && p[0][0] == 'h')
	{
		ft_add_bit(&(opt->modif), 1, 1);
		ft_add_bit(&(opt->modif), 0, 0);
		ret += 1;
	}
	else if (ft_read(&(opt->modif), 2) && p[0][0] == 'l')
	{
		ft_add_bit(&(opt->modif), 1, 3);
		ft_add_bit(&(opt->modif), 0, 2);
		ret += 1;
	}
	else
		ret = ft_fill_opt(&(opt->modif), p[0][0], "hhllL");
	return (ret);
}

static int		ft_check(char c)
{
	char	*tab;
	int		i;

	tab = ft_memalloc(10);
	tab = ft_strncpy(tab, "lLh#0-+ .", 10);
	i = -1;
	while (tab[++i])
		if (c == tab[i] || ft_isdigit(c))
		{
			ft_strdel(&tab);
			return (1);
		}
	ft_strdel(&tab);
	return (0);
}

void			ft_fill_t_option(t_option *opt, char **p)
{
	p[0]++;
	while (p[0][0] && !ft_is_conv(p[0][0]) && ft_check(p[0][0]))
	{
		p[0] += ft_fill_length_mod(opt, p);
		if (!ft_read(&(opt->option), 5) && ft_isdigit(p[0][0]) &&
				p[0][0] != '0')
		{
			opt->width = ft_atoi(p[0]);
			p[0] += ft_dbl_len(ft_atoi(p[0]));
		}
		else if (ft_read(&(opt->option), 5) && ft_isdigit(p[0][0]))
		{
			opt->precision = ft_atoi(p[0]);
			p[0] += ft_dbl_len(ft_atoi(p[0]));
		}
		p[0] += ft_fill_opt(&(opt->option), p[0][0], "-+0 #.");
	}
	ft_fill_opt(&(opt->flag), p[0][0], "%uoxX");
}

char			*ft_what_base(t_option opt)
{
	if (opt.flag & L_O)
		return ("01234567");
	else if (opt.flag & LL_X)
		return ("0123456789abcdef");
	else if (opt.flag & LD_X)
		return ("0123456789ABCDEF");
	else
		return ("0123456789");
}
