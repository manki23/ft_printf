/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 02:05:31 by manki             #+#    #+#             */
/*   Updated: 2019/07/28 14:33:11 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char			*ft_charcat(char a, char *str, int len)
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

static char		*ft_saveline(t_define var[], char *ret, int i)
{
/*	if ((int)ft_strlen(ret) < var->m_end + 1)
	{
		i = (int)ft_strlen(ret) - 1;
		while (++i <= var->m_end)
		{
			ret = ft_realloc(ret, ft_strlen(ret) + 2);
			ret = ft_strcat(ret, "0");
		}
	}*/
	(void)i;
	if (ft_is_max(ret, var->e_start, var->e_end) &&
			!ft_is_null(ret, var->m_start, var->m_end))
	{
		ret = ft_realloc(ret, 4);
		ret = ft_strncpy(ret, "nan", 4);
	}
	if (ft_is_max(ret, 0, var->e_end) &&
			ft_is_null(ret, var->m_start, var->m_end))
	{
		ret = ft_realloc(ret, 5);
		ret = ft_strncpy(ret, "-inf", 5);
	}
	if (ft_is_max(ret, var->e_start, var->e_end) &&
			ft_is_null(ret, var->m_start, var->m_end))
	{
		ret = ft_realloc(ret, 4);
		ret = ft_strncpy(ret, "inf", 4);
	}
	return (ret);
}

char			*ft_dbl_to_str(double arg, t_define var)
{
	char			*ret;
	unsigned char	*buff;

	buff = ft_memalloc(var.buf + 1);
	ft_memcpy(buff, &arg, var.buf);
	ret = ft_ctob(buff, var.buf);
	ret = ft_saveline(&var, ret, 0);
	ft_strdel((char **)&buff);
	return (ret);
}

uint64_t		*ft(uint64_t *dst, const void *src, size_t n)
{
	size_t		i;
	uint64_t	*s;

	i = 0;
	s = (uint64_t *)src;
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}

char			*ft_ldb_to_str(long double arg, t_define *var)
{
	char			*ret;
	unsigned char	*buff;

	ft_setvar(var, 1, arg, (double)arg);
	buff = (unsigned char *)&arg;
	buff -= 6;
	ret = ft_ctob(buff, var->buf);
	ret = ft_saveline(var, ret, 0);
	return (ret);
}
