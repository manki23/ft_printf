/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:15:35 by manki             #+#    #+#             */
/*   Updated: 2019/07/03 12:14:06 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_len(unsigned long long n, char base[])
{
	unsigned long long	len;

	len = ft_strlen(base);
	if (n < len)
		return (1);
	else
		return (ft_len(n / len, base) + ft_len(n % len, base));
}

static void		ft_nb(char *s, unsigned long long n, int i, char base[])
{
	unsigned long long	len;

	len = ft_strlen(base);
	if (n < len)
		s[i] = base[n];
	else
	{
		ft_nb(s, n / len, i, base);
		ft_nb(s, n % len, (i + ft_len(n / len, base)), base);
	}
}

static int		ft_isvalid_base(char b[], int size)
{
	int		i;
	int		ok;

	ok = 1;
	while (ok && size > 0)
	{
		i= 0;
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

static void		ft_fill(char *res, char base[], unsigned long long n, int len)
{
	ft_nb(res, n, 0, base);
	res[len] = '\0';
}

char			*ft_ulltoa_base(unsigned long long n, char base[])
{		
	char	*res;
	int		len;

	if (ft_strlen(base) > 1 && ft_isvalid_base(base, ft_strlen(base) - 1))
	{
		len = ft_len(n, base);
		if (!(res = ft_strnew(len)) && !ft_memset(res, '\0', len + 1))
			return (NULL);
		ft_fill(res, base, n, ft_len(n, base));
		return (res);
	}
	return (NULL);
}
