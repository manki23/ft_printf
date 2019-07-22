/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afficher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:33:44 by manki             #+#    #+#             */
/*   Updated: 2019/07/22 16:32:19 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_afficher_bit(char *str, int mod)
{
	int		i;

	ft_putstr("[");
	i = -1;
	while (++i < (int)ft_strlen(str))
	{
		ft_putchar(str[i]);
		if (!((i + 1) % mod))
			ft_putchar(' ');
	}
	ft_putstr("]\n");
}

void		ft_display(t_option opt)
{
	ft_putstr("flag =	|");
	ft_putstr(ft_ulltoa_base(opt.flag, "01"));
	ft_putstr("| option =	|");
	ft_putstr(ft_ulltoa_base(opt.option, "01"));
	ft_putstr("| modif =	|");
	ft_putstr(ft_ulltoa_base(opt.modif, "01"));
	ft_putstr("| width =	|");
	ft_putstr(ft_lltoa(opt.width));
	ft_putstr("| precision =	|");
	ft_putstr(ft_lltoa(opt.precision));
	ft_putstr("|\n");
}
