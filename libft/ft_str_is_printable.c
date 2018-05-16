/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 09:25:40 by manki             #+#    #+#             */
/*   Updated: 2017/11/19 09:29:27 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_printable(char *str)
{
	int		i;
	int		res;

	res = 1;
	i = -1;
	while (res && str[++i])
		if (ft_iscntrl(str[i]))
			res = 0;
	return (res);
}
