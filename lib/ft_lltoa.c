/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:31:32 by manki             #+#    #+#             */
/*   Updated: 2019/07/02 19:31:38 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int		ft_nblen(long long n)
{
	if (n < 10 && n > -10)
		return (1);
	else
		return (ft_nblen(n / 10) + ft_nblen(n % 10));
}

static void		ft_nb(char *s, long long n, int i, int len)
{
	if (n < 10 && n > -10)
	{
		if (n < 0)
			s[i] = '0' - n;
		else
			s[i] = '0' + n;
	}
	else
	{
		ft_nb(s, n / 10, i, len);
		ft_nb(s, n % 10, (i + ft_nblen(n / 10)), len);
	}
}

static void		ft_fill(char *res, int i, long long n, int len)
{
	ft_nb(res, n, i, len);
	res[len] = '\0';
}

char			*ft_lltoa(long long n)
{
	int		neg;
	char	*res;

	neg = 0;
	if (n < 0)
		neg = 1;
	if (neg)
	{
		if (!(res = (char *)malloc(sizeof(char) * (ft_nblen(n) + 2))))
			return (NULL);
		res[0] = '-';
		ft_fill(res, 1, n, ft_nblen(n) + 1);
	}
	else
	{
		if (!(res = (char *)malloc(sizeof(char) * (ft_nblen(n) + 1))))
			return (NULL);
		ft_fill(res, 0, n, ft_nblen(n));
	}
	return (res);
}
