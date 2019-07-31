/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 02:05:31 by manki             #+#    #+#             */
/*   Updated: 2019/07/31 11:33:17 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_setvar(t_define *var, int ldb, long double b, double a)
{
	if (ldb)
	{
		var->e_start = LDB_E_START;
		var->e_end = LDB_E_END;
		var->m_start = LDB_M_START;
		var->m_end = LDB_M_END;
		var->e_bias = LDB_E_BIAS;
		var->buf = LDB_BUF;
		var->b = b;
		var->a = a;
	}
	else
	{
		var->e_start = E_START;
		var->e_end = E_END;
		var->m_start = M_START;
		var->m_end = M_END;
		var->e_bias = E_BIAS;
		var->buf = BUF;
		var->a = a;
	}
}

static char		*ft_saveline(t_define var[], char *ret)
{
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

char			*ft_dbl_to_str(t_define var)
{
	char			*ret;
	unsigned char	*buff;

	if (var.buf == LDB_BUF)
	{
		buff = (unsigned char *)&(var.b);
		buff -= 6;
	}
	else
		buff = (unsigned char *)&(var.a);
	ret = ft_ctob(buff, var.buf);
	ret = ft_saveline(&var, ret);
	return (ret);
}
