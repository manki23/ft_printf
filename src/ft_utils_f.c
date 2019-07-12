/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:14:41 by manki             #+#    #+#             */
/*   Updated: 2019/07/12 14:00:14 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>
t_byte			ft_is_max(char *bit_nb, int from, int to)
{
	while (from <= to)
	{
		if (bit_nb[from] != '1')
			return (0);
		from++;
	}
	return (1);
}

t_byte			ft_is_null(char *bit_nb, int from, int to)
{
	while (from <= to)
	{
		if (bit_nb[from] != '0')
			return (0);
		from++;
	}
	return (1);
}

static char			*ft_div2(char *nb)
{
	char	*res;
	char	tmp[3];
	int		x;
	char	c;

	res = ft_strjoin("", "0");
	while (nb[ft_strlen(nb) - 1])
	{
		c = nb[ft_strlen(nb) - 1];
		tmp[0] = '0' + ((c - '0') / 2);
		tmp[1] = '\0';
		if ((c - '0') % 2)
		{
			x = 0;
			if (ft_strlen(res) > 1)
				x += res[0] - '0';
			x += 5;
			res[0] = '0' + x;
		}
		res = ft_strjoin(tmp, res);
		nb[ft_strlen(nb) - 1] = '\0';
	}
	return (res);
}

unsigned long long	ft_mul2(char *nb, int i, int end)
{
	unsigned long long	res;

	res = 0;
	if (i <= (int)ft_strlen(nb) && end <= (int)ft_strlen(nb))
	{
		while (++i <= end)
			if (nb[i] == '1')
				res += ft_ipower(2, end - i);
	}
	return (res);
}

char				*ft_traduct(char *nb, int op, double f)
{
	char *res;
	int zero;

	res = nb;
	while (op > 0)
	{
		res = ft_div2(res);
		op--;
	}
	while (res[0] == '0')
		res++;
	zero = 0;
	f = f - (long long)f;
	while ((f > 0 && f < 1) || (f < 0 && f > -1))
	{
		f *= 10;
		if ((f > 0 && f < 1) || (f < 0 && f > -1))
			res = ft_strjoin("0", res);
	}
	return (res);
}
