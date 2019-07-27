/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:14:41 by manki             #+#    #+#             */
/*   Updated: 2019/07/27 14:59:26 by manki            ###   ########.fr       */
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

static char			*ft_saveline(char *nb, char *res, int end)
{
	char	*tmp;
	char	*tmp2;

	if (nb[0] == '1')
	{
		tmp = ft_strpower("2", end);
		tmp2 = res;
		res = ft_stradd(res, tmp, ft_strlen(res), ft_strlen(tmp));
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	return (res);
}

char				*ft_mul2_traduct(char *nb, int i, int end, t_define var)
{
	char	*res;
	int		nb_len;

	if (ft_is_null(nb, 1, ft_strlen(nb) - 1))
		return ("0");
	nb_len = var.buf * CHAR_BIT;
	if (!(res = ft_memalloc(nb_len)))
		return (NULL);
	if (i <= nb_len && end <= nb_len)
		while (++i <= end)
			res = ft_saveline(&nb[i], res, end - i);
	else if (end > var.m_end)
	{
		end -= var.e_end;
		while (++i <= var.m_end)
		{
			end--;
			res = ft_saveline(&nb[i], res, end);
		}
	}
	return (res);
}

char				*ft_newtrad(char f_str[], int index, int i)
{
	char	*res;
	char	*tmp;
	int		tmp_len;

	res = ft_memalloc(2);
	if (!ft_is_null(f_str, 1, ft_strlen(f_str) - 1))
	{
		res[0] = '0';
		while (++i + index <= (int)ft_strlen(f_str))
		{
			if (f_str[index + i] == '1')
			{
				tmp = ft_memalloc(3);
				tmp[0] = '1';
				tmp_len = -1;
				while (++tmp_len <= i)
					tmp = ft_strdivby2(tmp, tmp_len + 1);
				res = ft_leftadd(res, tmp, ft_strlen(res), tmp_len + 1);
			}
		}
	}
	return (res);
}
