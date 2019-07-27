/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:51:42 by manki             #+#    #+#             */
/*   Updated: 2019/07/27 15:33:22 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_putdot(char *str, size_t str_len, int position)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = str;
	str = ft_memalloc(str_len + 2);
	i = 0;
	j = 0;
	while (tmp[i - j])
	{
		if (i == position)
		{
			str[i + j] = '.';
			j++;
		}
		else
			str[i] = tmp[i - j];
		i++;
	}
	if (str_len == 1)
		str[1] = '.';
	ft_strdel(&tmp);
	return (str);
}
