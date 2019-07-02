/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:32:34 by manki             #+#    #+#             */
/*   Updated: 2019/07/02 19:21:51 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_display_option(t_option opt)
{
	ft_putstr("\n-------------------------\n");
	ft_putstr("opt->minus = ");
	ft_putstr(ft_lltoa(opt.minus));
	ft_putstr("\nopt->plus = ");
	ft_putstr(ft_lltoa(opt.plus));
	ft_putstr("\nopt->zero = ");
	ft_putstr(ft_lltoa(opt.zero));
	ft_putstr("\nopt->space = ");
	ft_putstr(ft_lltoa(opt.space));
	ft_putstr("\nopt->hashtag = ");
	ft_putstr(ft_lltoa(opt.hashtag));
	ft_putstr("\nopt->point = ");
	ft_putstr(ft_lltoa(opt.point));
	ft_putstr("\nopt->width = ");
	ft_putstr(ft_lltoa(opt.width));
	ft_putstr("\nopt->precision = ");
	ft_putstr(ft_lltoa(opt.precision));
	ft_putstr("\nopt->hh = ");
	ft_putstr(ft_lltoa(opt.hh));
	ft_putstr("\nopt->h = ");
	ft_putstr(ft_lltoa(opt.h));
	ft_putstr("\nopt->ll = ");
	ft_putstr(ft_lltoa(opt.ll));
	ft_putstr("\nopt->l = ");
	ft_putstr(ft_lltoa(opt.l));
	ft_putstr("\nopt->ld = ");
	ft_putstr(ft_lltoa(opt.ld));
	ft_putstr("\n--------------------------\n");
}
