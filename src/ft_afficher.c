/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afficher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:33:44 by manki             #+#    #+#             */
/*   Updated: 2019/07/17 17:14:14 by manki            ###   ########.fr       */
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
