/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:32:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/29 14:35:26 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_calc(char *res, int *i, char c, t_byte *restraint)
{
	if (c > 9)
	{
		res[*i] = (c % 10) + '0';
		restraint[0] = c / 10;
	}
	else
	{
		res[*i] = c + '0';
		restraint[0] = 0;
	}
	i[0]--;
}

char		*ft_strmul(char a[], char b[], size_t a_len, size_t b_len)
{
	char	*res;
	char	*res2;
	t_byte	r;
	t_coord	c;
	char	*tmp;

	res2 = ft_memalloc(a_len + b_len + 1);
	c.j = 0;
	while ((--b_len + 1) && a_len)
	{
		res = ft_memalloc(a_len + c.j + 2);
		c.i = a_len;
		r = 0;
		while (c.i)
			ft_calc(res, &c.i, (a[c.i - 1] - '0') * (b[b_len] - '0') + r, &r);
		res[c.i] = r + '0';
		tmp = res2;
		res2 = ft_stradd(res2, res, ft_strlen(res2), a_len + c.j + 1);
		ft_strdel(&tmp);
		ft_strdel(&res);
		c.j++;
	}
	if (res2[0] == '0')
		res2 = ft_strncpy(res2, &res2[1], ft_strlen(res2));
	return (res2);
}
