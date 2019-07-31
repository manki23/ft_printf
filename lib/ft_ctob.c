/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:32:22 by manki             #+#    #+#             */
/*   Updated: 2019/07/31 11:31:08 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char			*ft_ctob(unsigned char tab[], int size)
{
	char	*res;
	int		len;
	int		j;
	int		calc;

	res = ft_memalloc((size * CHAR_BIT) + 1);
	ft_memset(res, '0', size * CHAR_BIT);
	j = 0;
	while (--size >= 0)
	{
		len = CHAR_BIT - 1;
		calc = tab[size];
		while (len >= 0)
		{
			res[j + len] = '0' + calc % 2;
			calc /= 2;
			len--;
		}
		j += CHAR_BIT;
	}
	return (res);
}
