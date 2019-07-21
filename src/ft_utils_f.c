/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:14:41 by manki             #+#    #+#             */
/*   Updated: 2019/07/21 16:23:25 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_byte				ft_is_max(char *bit_nb, int from, int to)
{
	while (from <= to)
	{
		if (bit_nb[from] != '1')
			return (0);
		from++;
	}
	return (1);
}

t_byte				ft_is_null(char *bit_nb, int from, int to)
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
//	char	*tmp;

	res = ft_strjoin("", "0");
//	tmp = res;
	while (ft_isdigit(nb[ft_strlen(nb) - 1]))
	{
		c = nb[ft_strlen(nb) - 1];
		tmp[0] = '0' + ((c - '0') / 2);
	//		ft_putstr("[");
	//		ft_putchar(nb[ft_strlen(nb) - 1]);
	//		ft_putstr("]");
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
//		ft_strdel(&tmp);
		nb[ft_strlen(nb) - 1] = '\0';
	}
//	ft_strdel(&nb);
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
	char	*res;
	int		zero;

	zero = ft_is_null(nb, 0, ft_strlen(nb) - 1);
	if (!zero)
	{
		res = nb;
		while (op > 0)
		{
		//	ft_putstr("[");
		//	ft_putstr(res);
		//	ft_putstr("]\n");
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
	return ("");
}
