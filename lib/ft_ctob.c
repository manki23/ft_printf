/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:32:22 by manki             #+#    #+#             */
/*   Updated: 2019/07/28 14:34:17 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_nb(char *s, unsigned char tab, int i, int len)
{
	while (--len >= 0)
	{
		s[i + len] = '0' + (tab % 2);
		tab /= 2;
	}
}

static void		ft_fill(char *res, unsigned char tab[], int len)
{
	int		j;

	j = 0;
	while (--len >= 0)
	{
		ft_nb(res, tab[len], j, CHAR_BIT);
		j += CHAR_BIT;
	}
}

char			*ft_ctob(unsigned char tab[], int size)
{
	char	*res;
	int		len;

	len = size * CHAR_BIT;
	if (!(res = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	ft_memset(res, '\0', len + 2);
	ft_memset(res, '0', len);
	ft_fill(res, tab, size);
	return (res);
}
