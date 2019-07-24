/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:14:41 by manki             #+#    #+#             */
/*   Updated: 2019/07/24 13:39:33 by manki            ###   ########.fr       */
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

	res = ft_memalloc(2);
	res[0] = '0';
	while (ft_isdigit(nb[ft_strlen(nb) - 1]))
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

unsigned long long	ft_mul2_trash(char *nb, int i, int end)
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

char				*ft_mul2_traduct(char *nb, int i, int end)
{
	char	*res;
	char	*tmp;
	int		nb_len;
	int		zero;

	zero = ft_is_null(nb, 1, ft_strlen(nb) - 1);
	if (!zero)
	{
		nb_len = BUF * CHAR_BIT;
		if (!(res = ft_memalloc(nb_len)))
			return (NULL);
		if (i <= nb_len && end <= nb_len)
		{
			while (++i <= end)
			{
				if (nb[i] == '1')
				{
					tmp = ft_strpower("2", end - i);
					res = ft_stradd(res, tmp, ft_strlen(res), ft_strlen(tmp));
				}
			}
		}
		else if (end > M_END)
		{
			end -= E_END;
			while (++i <= M_END)
			{
				end--;
				if (nb[i] == '1')
				{
					tmp = ft_strpower("2", end);
					res = ft_stradd(res, tmp, ft_strlen(res), ft_strlen(tmp));
				}
			}
		}
		return (res);
	}
	return ("0");
}

char				*ft_newtrad(char *f_str, int index)
{
	char	*res;
	char	*tmp;
	int		tmp_len;
	int		zero;
	int		i;

	zero = ft_is_null(f_str, 1, ft_strlen(f_str));
	if (!zero)
	{
		i = 0;
		res = ft_memalloc(2);
		res[0] = '0';
		while (i + index <= (int)ft_strlen(f_str))
		{
			if (f_str[index + i] == '1')
			{
			//	if (tmp_len > 0)
			//		ft_strdel(tmp);
				tmp = ft_memalloc(3);
				tmp[0] = '1';
				tmp_len = -1;
				while (++tmp_len <= i)
					tmp = ft_strdivby2(tmp, tmp_len + 1);
/*				ft_putstr("(");
				ft_putstr(tmp);
				ft_putstr(")\n");
				ft_putstr("[");
				ft_putstr(res);
				ft_putstr("]\n");*/
				res = ft_leftadd(res, tmp, ft_strlen(res), tmp_len + 1);
			}
			i++;
		}
		return (res);
	}
	return ("");
}
/*
				ft_putstr("(");
				ft_putstr(tmp);
				ft_putstr(")\n");
				*/

char				*ft_traduct(char *nb, int op, double f)
{
	char	*res;
	int		zero;

	zero = ft_is_null(nb, 1, ft_strlen(nb) - 1);
	if (!zero)
	{
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
	return ("");
}
