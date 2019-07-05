/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:36:43 by manki             #+#    #+#             */
/*   Updated: 2019/07/05 11:02:11 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_nblen(long long n)
{
	if (n < 10 && n > -10)
		return (1);
	else
		return (ft_nblen(n / 10) + ft_nblen(n % 10));
}

int		ft_unblen_base(unsigned long long n, char *base)
{
	unsigned long long	len;

	len = ft_strlen(base);
	if (n < len)
		return (1);
	else
		return (ft_unblen_base(n / len, base) + ft_unblen_base(n % len, base));
}

void	ft_tr(char *s, char old, char neww)
{
	while (s[0])
	{
		if (s[0] == old)
			s[0] = neww;
		s++;
	}
}

int		ft_ipower(int nb, int power)
{
	int		i;
	int		nb_bis;

	i = 1;
	nb_bis = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (i < power)
	{
		nb = nb * nb_bis;
		i++;
	}
	return (nb);
}
