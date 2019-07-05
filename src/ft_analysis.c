/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:57:23 by manki             #+#    #+#             */
/*   Updated: 2019/07/05 12:22:13 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_conv	g_tab[] =
{
	{"d", &ft_fill_di_output},
	{"i", &ft_fill_di_output},
	{"o", &ft_fill_uoxx_output},
	{"u", &ft_fill_uoxx_output},
	{"x", &ft_fill_uoxx_output},
	{"X", &ft_fill_uoxx_output},
	{"%", &ft_fill_c_output},
	{"c", &ft_fill_c_output},
	{"s", &ft_fill_s_output},
	{"p", &ft_fill_p_output},
	{"f", &ft_fill_f_output}
};

int		ft_is_conv(char c)
{
	int		i;

	i = -1;
	while (++i < 11)
	{
		if (c == (g_tab + i)->c[0])
			return (1);
	}
	return (0);
}

char	*ft_conv(char **p, va_list *ap, size_t *size)
{
	t_option	opt;
	char		*output;
	int			i;
//	t_byte		tab[3];
//	char		*opt;

	while (p[0][0])
	{
		ft_init_option(&opt);
		ft_fill_t_option(&opt, p);
		i = -1;
		while (g_tab + ++i)
		{
			if (p[0][0] == (g_tab + i)->c[0])
			{
				output = (g_tab + i)->fun(opt, ap, size);
				p[0]++;
				return (output);
			}
		}
		return ("Error\n");
	}
	return (NULL);
}
