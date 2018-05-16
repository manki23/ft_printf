/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:03:28 by manki             #+#    #+#             */
/*   Updated: 2017/11/13 16:32:01 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_print(int n)
{
	if (n > -10 && n < 0)
		ft_putchar('0' - n);
	else if (n >= 0 && n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_print(n / 10);
		ft_print(n % 10);
	}
}

void			ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	ft_print(n);
}
