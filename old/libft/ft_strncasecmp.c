/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 10:01:01 by manki             #+#    #+#             */
/*   Updated: 2017/11/19 11:10:52 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	if (n > 0)
	{
		i = 0;
		while ((i < n - 1) && s1[i] && s2[i] && (ft_tolower((char)s1[i]) ==
		ft_tolower((char)s2[i])))
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
