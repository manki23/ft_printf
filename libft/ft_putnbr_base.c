/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 11:49:39 by manki             #+#    #+#             */
/*   Updated: 2017/11/19 12:27:03 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_print(int n, char *b, int len)
{
	if (n <= -len || n >= len)
	{
		ft_print(n / len, b, len);
		ft_print(n % len, b, len);
	}
	else if (n < 0)
		ft_putchar(b[-n]);
	else
		ft_putchar(b[n]);
}

static int		ft_isvalid_base(char *b, int size)
{
	int		i;
	int		ok;

	ok = 1;
	while (ok && size > 0)
	{
		i = 0;
		while (ok && i < size)
		{
			if (b[size] == b[i])
				ok = 0;
			i++;
		}
		if (b[size] == '+' || b[size] == '-' || b[size] < 32 || b[size] == 127)
			ok = 0;
		size--;
	}
	return (ok);
}

void			ft_putnbr_base(int nbr, char *base)
{
	if (ft_strlen(base) > 1 && ft_isvalid_base(base, ft_strlen(base) - 1))
	{
		if (nbr < 0)
			ft_putchar('-');
		ft_print(nbr, base, ft_strlen(base));
	}
}
