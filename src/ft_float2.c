/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:08:23 by manki             #+#    #+#             */
/*   Updated: 2019/07/24 22:48:42 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_float_to_str(double arg)
{
	char			*ret;
	int				i;
	unsigned char	buff[BUF];

	ft_memcpy(buff, &arg, BUF);
	ret = ft_ctob(buff, BUF);
	if ((int)ft_strlen(ret) < M_END + 1)
	{
		i = (int)ft_strlen(ret) - 1;
		while (++i <= M_END)
		{
			ret = ft_strjoin(ret, "0");
		}
	}
	if (ft_is_max(ret, E_START, E_END) && !ft_is_null(ret, M_START, M_END))
		return ("nan");
	if (ft_is_max(ret, 0, E_END) && ft_is_null(ret, M_START, M_END))
		return ("-inf");
	if (ft_is_max(ret, E_START, E_END) && ft_is_null(ret, M_START, M_END))
		return ("inf");
	return (ret);
}

char		*ft_charcat(char a, char *str, int len)
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

static t_byte	ft_rounding(char *nb, int *j, int *overflow)
{
	if (nb[*j] == '9')
	{
		nb[*j] = '0';
		if (*j == 0)
			overflow[0] = 1;
	}
	else if (nb[*j] != '.')
	{
		nb[*j] += 1;
		j[0] = 0;
	}
	j[0]--;
	return (0);
}

static char		*ft_dotfive(char *nb, int dot_pos, int *overflow)
{
	int		i;
	int		add;

	i = dot_pos + 1;
	add = 0;
	while (nb[++i] && !add)
	{
		if (nb[i] > '0')
			add = 1;
	}
	if (nb[i] == '\0' && ((nb[dot_pos - 1] - '0') % 2))
		add = 1;
	i = dot_pos - 1;
	while (add && i >= 0 && nb[i] == '9')
	{
		nb[i] = '0';
		i--;
	}
	if (i != -1)
		nb[i] += add;
	else
		overflow[0] = 1;
	return (nb);
}

char		*ft_roundd(char *nb, int pos, int *dot_pos, int precision)
{
	int		i;
	int		j;
	int		overflow;

	i = pos + 1;
	j = 0;
	overflow = 0;
	if (nb[pos] == '.' && nb[pos + 1] == '5' && precision == 0)
		nb = ft_dotfive(nb, dot_pos[0], &overflow);
	else
	{
		while (nb[i] == '5' || nb[i] == '.')
			i++;
		if (nb[i] && nb[i] > '5' && nb[pos] < '9' && nb[pos] != '.')
		{
			if (nb[pos] == '.')
				nb[pos - 1] += 1;
			else
				nb[pos] += 1;
		}
		else if (nb[i] && (nb[i] > '5'))
		{
			j = pos;
			while (j >= 0)
				ft_rounding(nb, &j, &overflow);
		}
	}
	nb[pos + 1] = '\0';
	if (overflow)
		nb = ft_charcat('1', nb, pos + 1);
	dot_pos[0] += overflow;
	return (nb);
}
/*
   ft_putstr("(");
   ft_putstr(nb);
   ft_putstr(")");
   ft_putchar(j + '0');
   */
