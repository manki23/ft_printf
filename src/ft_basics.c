/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:04:16 by manki             #+#    #+#             */
/*   Updated: 2019/07/25 02:51:10 by manki            ###   ########.fr       */
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

char	*ft_strpower(char *nb, int power)
{
	int		i;
	char	*nb_bis;

	if (power == 0)
		return ("1");
	else if (power > 0)
	{
		nb_bis = nb;
		i = 0;
		while (++i < power)
		{
			nb = ft_strmul(nb, nb_bis, ft_strlen(nb), ft_strlen(nb_bis));
		}
	}
	return (nb);
}

double	ft_ipower(double nb, double power)
{
	long long	i;
	double		nb_bis;

	if (power == 0)
		return (1);
	else if (power > 0)
	{
		nb_bis = nb;
		i = 0;
		while (++i < power)
			nb = nb * nb_bis;
	}
	else if (power < 0)
	{
		nb = 1 / nb;
		nb_bis = nb;
		i = 0;
		while (--i > power)
			nb = nb * nb_bis;
	}
	return (nb);
}
