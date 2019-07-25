/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:49:00 by manki             #+#    #+#             */
/*   Updated: 2019/07/25 01:18:21 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_calc(char *res, size_t *i, char c, t_byte *restraint)
{
	if (c > '9')
	{
		res[0] = c - 10;
		restraint[0] = 1;
	}
	else
	{
		res[0] = c;
		restraint[0] = 0;
	}
	i[0]++;
}

char			*ft_stradd(char *a, char *b, size_t a_len, size_t b_len)
{
	t_byte	rest;
	char	*res;
	size_t	i;
	size_t	len;

	len = ft_max(a_len, b_len) + 1;
	if (!(res = ft_memalloc(len + 1)))
		return (NULL);
	rest = 0;
	i = 0;
	while (a[i] && b[i])
		ft_calc(&res[--len], &i, a[--a_len] + b[--b_len] + rest - '0', &rest);
	if (a[i])
		while (a[i])
			ft_calc(&res[--len], &i, a[--a_len] + rest, &rest);
	else if (b[i])
		while (b[i])
			ft_calc(&res[--len], &i, b[--b_len] + rest, &rest);
	res[0] = rest + '0';
	if (rest)
		return (res);
	else
		return (&res[1]);
}

static void		ft_copy(char *res, char *src, size_t *src_len, size_t end)
{
	while (end < src_len[0])
	{
		src_len[0]--;
		res[*src_len] = src[*src_len];
	}
}

char			*ft_leftadd(char *a, char *b, size_t a_len, size_t b_len)
{
	t_byte	rest;
	char	*res;
	size_t	i;
	char	c;

	if (!(res = ft_memalloc(ft_max(a_len, b_len) + 1 + 1)))
		return (NULL);
	rest = 0;
	i = 0;
	ft_copy(res, b, &b_len, a_len);
	ft_copy(res, a, &a_len, b_len);
	while (a_len == b_len && a_len && b_len)
	{
		c = a[--a_len] + b[--b_len] + rest - '0';
		ft_calc(&res[a_len], &i, c, &rest);
	}
	return (res);
}
