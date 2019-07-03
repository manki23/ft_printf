/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:03:08 by manki             #+#    #+#             */
/*   Updated: 2019/07/03 15:52:46 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int		ft_nblen(unsigned long long n)
{
	if (n < 10)
		return (1);
	else
		return (ft_nblen(n / 10) + ft_nblen(n % 10));
}

static void		ft_nb(char *s, unsigned long long n, int i, int len)
{
	if (n < 10)
		s[i] = '0' + n;
	else
	{
		ft_nb(s, n / 10, i, len);
		ft_nb(s, n % 10, (i + ft_nblen(n / 10)), len);
	}
}

static void		ft_fill(char *res, int i, unsigned long long n, int len)
{
	ft_nb(res, n, i, len);
	res[len] = '\0';
}

char			*ft_ulltoa(unsigned long long n)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (ft_nblen(n) + 1))))
		return (NULL);
	ft_fill(res, 0, n, ft_nblen(n));
	return (res);
}
