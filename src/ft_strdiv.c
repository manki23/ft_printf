/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdiv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:22:29 by manki             #+#    #+#             */
/*   Updated: 2019/07/23 19:51:01 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_strdivby2(char a[], size_t a_len)
{
	char	*res;
	char	c;
	short	x;
	size_t	i;

	if (!(res = ft_memalloc(a_len + 2)))
		return (NULL);
	i = a_len;
	while (i)
	{
		c = a[--i] - '0';
		if (c % 2)
		{
			x = 0;
			if (i < a_len - 1)
				x += res[i + 1] - '0';
			x += 5;
			res[i + 1] = x + '0';
		}
		c /= 2;
		res[i] = c + '0';
	}
	return (res);
}
