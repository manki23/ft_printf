/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:16:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/05 14:50:20 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_add_bit(t_byte *tab, t_byte bit, t_byte at)
{
	if (bit)
		tab[at / 8] |= 1 << (at & 7);
	else
		tab[at / 8] &= ~(1 << (at & 7));
}

t_byte		ft_read_bit(t_byte *tab, t_byte at)
{
	return ((tab[at / 8] & (1 << (at & 7))) >> (at & 7));
}

