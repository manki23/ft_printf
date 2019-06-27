/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:32:34 by manki             #+#    #+#             */
/*   Updated: 2019/06/26 15:38:12 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_display_option(t_option opt)
{
	ft_putstr("\n-------------------------\n");
	ft_putstr("opt->minus = ");
	ft_putstr(ft_itoa(opt.minus));
	ft_putstr("\nopt->plus = ");
	ft_putstr(ft_itoa(opt.plus));
	ft_putstr("\nopt->zero = ");
	ft_putstr(ft_itoa(opt.zero));
	ft_putstr("\nopt->space = ");
	ft_putstr(ft_itoa(opt.space));
	ft_putstr("\nopt->hashtag = ");
	ft_putstr(ft_itoa(opt.hashtag));
	ft_putstr("\nopt->point = ");
	ft_putstr(ft_itoa(opt.point));
	ft_putstr("\nopt->width = ");
	ft_putstr(ft_itoa(opt.width));
	ft_putstr("\nopt->precision = ");
	ft_putstr(ft_itoa(opt.precision));
	ft_putstr("\n--------------------------\n");
}
