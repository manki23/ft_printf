/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:36:43 by manki             #+#    #+#             */
/*   Updated: 2019/07/02 19:15:11 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_nblen(long long n)
{
	if (n < 10 && n > -10)
		return (1);
	else
		return (ft_nblen(n / 10) + ft_nblen(n % 10));
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
