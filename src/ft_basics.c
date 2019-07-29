/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:04:16 by manki             #+#    #+#             */
/*   Updated: 2019/07/29 15:34:03 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_unblen_base(unsigned long long n, char *base)
{
	unsigned long long	len;
	int					res;

	len = ft_strlen(base);
	res = 1;
	while (n >= len)
	{
		n /= len;
		res++;
	}
	return (res);
}

void	ft_tr(char *s, char old, char neww)
{
	while (s[0])
	{
		if (s[0] == old)
			s[0] = neww;
		s++;
	}
}

char	*ft_charcat(char a, char *str, int len)
{
	int		i;
	char	c;

	str = ft_realloc(str, len + 2);
	i = 0;
	while (str[i + 1])
	{
		c = str[i + 1];
		str[i + 1] = str[0];
		str[0] = c;
		i++;
	}
	str[i + 1] = str[0];
	str[0] = a;
	return (str);
}

char	*ft_bischarcat(char a, char b, char *str, int len)
{
	str = ft_charcat(b, str, len);
	str = ft_charcat(a, str, len + 1);
	return (str);
}

char	*ft_strpower(char *nb, int nb_len, int power)
{
	int		i;
	char	*nb_bis;
	char	*tmp;
	char	*res;
	int		res_len;

	res = ft_memalloc(nb_len + 1);
	if (power == 0)
		res = ft_strncpy(res, "1", 2);
	else if (power > 0)
	{
		res = ft_strncpy(res, nb, nb_len + 1);
		res_len = nb_len;
		nb_bis = nb;
		i = 0;
		while (++i < power)
		{
			tmp = res;
			res = ft_strmul(tmp, nb_bis, ft_strlen(tmp), nb_len);
			ft_strdel(&tmp);
		}
	}
	return (res);
}
