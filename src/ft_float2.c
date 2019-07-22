/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:08:23 by manki             #+#    #+#             */
/*   Updated: 2019/07/22 15:57:55 by manki            ###   ########.fr       */
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

static void	ft_r(char *mantissa, int i)
{
	while (--i > 0)
	{
		if (mantissa[i] == '9')
			mantissa[i] = '0';
		else
		{
			mantissa[i] += 1;
			i = 0;
		}
	}
}

void		ft_round(char *mantissa, int precision)
{
	int		i;

	i = precision;
	while (mantissa[i] == '5')
		i++;
	if (mantissa[i] && mantissa[i] > '5' && mantissa[precision - 1] < '9')
		mantissa[precision - 1] += 1;
	else if (mantissa[i] && mantissa[i] > '5')
		ft_r(mantissa, precision);
	mantissa[precision] = '\0';
	if (precision == 0 && (mantissa[0] > '5' || mantissa[i] > '5'))
	{
		mantissa[0] = 'a';
		mantissa[1] = '\0';
	}
}

char		*ft_round2(char *nb, int len)
{
	int		add;

	add = 0;
	len = ft_strlen(nb) - 1;
	if (nb[len] == 'a')
	{
		nb[len] = '\0';
		len--;
		add++;
	}
	if (!ft_strchr(nb, '.') || nb[len] == '.')
	{
		if (nb[len] == '.')
			len--;
		while (add && len >= 0 && nb[len] == '9')
		{
			nb[len] = '0';
			len--;
		}
		if (len == -1)
		{
			nb = ft_strjoin("1", nb);
		}
		else
			nb[len] += add;
	}
	return (nb);
}
