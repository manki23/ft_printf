/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:34:31 by manki             #+#    #+#             */
/*   Updated: 2019/07/02 19:34:35 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_nb(char *s, long long n, int i, char base[])
{
	long long	len;

	len = ft_strlen(base);
	if (n < len && n > -len)
	{
		if (n < 0)
			s[i] = base[-n];
		else
			s[i] = base[n];
	}
	else
	{
		ft_nb(s, n / len, i, base);
		ft_nb(s, n % len, (i + ft_nblen(n / len)), base);
	}
}

static int		ft_isvalid_base(char b[], int size)
{
	int		i;
	int		ok;

	ok = 1;
	while (ok && size > 0)
	{
		i = 0;
		while (ok && i < size)
		{
			if (b[size] == b[i])
				ok = 0;
			i++;
		}
		if (b[size] == '+' || b[size] == '-' || b[size] < 32 || b[size] == 127)
			ok = 0;
		size--;
	}
	return (ok);
}

static void		ft_fill(char *res, char base[], long long n, int len)
{
	ft_nb(res, n, 0, base);
	res[len] = '\0';
}

char		*ft_lltoa_base(long long n, char base[])
{
	int		neg;
	char	*res;

	if (ft_strlen(base) > 1 && ft_isvalid_base(base, ft_strlen(base) - 1))
	{
		neg = 0;
		if (n < 0)
			neg = 1;
		if (neg)
		{
			if (!(res = (char *)malloc(sizeof(char) * (ft_nblen(n) + 2))))
				return (NULL);
			res[0] = '-';
			ft_fill(&res[1], base, n, ft_nblen(n) + 1);
		}
		else
		{
			if (!(res = (char *)malloc(sizeof(char) * (ft_nblen(n) + 1))))
				return (NULL);
			ft_fill(res, base, n, ft_nblen(n));
		}
		return (res);
	}
	return (NULL);
}
