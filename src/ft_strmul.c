/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:32:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/25 02:01:05 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_calc(char *res, size_t *i, char c, t_byte *restraint)
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
	t_byte	rest;
	size_t	i;
	size_t	j;

	res2 = ft_memalloc(a_len + b_len + 1);
	j = 0;
	while ((--b_len + 1) && a_len)
	{
		res = ft_memalloc(a_len + j + 2);
		i = a_len;
		rest = 0;
		while (i)
			ft_calc(res, &i, (a[i - 1] - '0') * (b[b_len] - '0') + rest, &rest);
		res[i] = rest + '0';
		while (++i - 1 < j)
			res[ft_strlen(res)] = '0';
		res2 = ft_stradd(res2, res, ft_strlen(res2), ft_strlen(res));
		ft_strdel(&res);
		j++;
	}
	if (res2[0] == '0')
		return (&res2[1]);
	return (res2);
}
