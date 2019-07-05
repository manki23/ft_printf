/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:16:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/05 12:21:48 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

#define OPT_MINUS 11
#define OPT_
#define OPT_
#define OPT_
#define OPT_
#define OPT_
#define OPT_
#define OPT_
#define OPT_
#define OPT_
#define OPT_

void		ft_add_bit(t_byte *opt, t_byte bit, t_byte at)
{
	if (bit)
		opt[at / 8] |= 1 << (at & 7);
	else
		opt[at / 8] &= ~(1 << (at & 7));
}

t_byte		ft_read_bit(t_byte *opt, t_byte at)
{
	return ((opt[at / 8] & (1 << (at & 7))) >> (at & 7));
}

static void	ft_modi(t_byte *tab, char **p)
{
	t_byte	inc;

	inc = 0;
	if (p[0][0] == 'h' && p[0][1] == 'h' && (inc = 2))
		ft_add_bit(tab, 1, 19;
	else if (p[0][0] == 'h' && p[0][1] != 'h' && (inc = 1))
		opt->h += 1;
	else if (p[0][0] == 'l' && p[0][1] == 'l' && (inc = 2))
		opt->ll += 1;
	else if (p[0][0] == 'l' && p[0][1] != 'l' && (inc = 1))
		opt->l += 1;
	else if (p[0][0] == 'L' && (inc = 1))
		opt->ld += 1;
	p[0] += inc;
}

void		ft_fill_tab(t_byte *tab, char **p)
{
	while ((++p[0])[0] && !ft_is_conv(p[0][0]))
	{
		ft_modi(tab, p);
	}

}
