/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:52:15 by manki             #+#    #+#             */
/*   Updated: 2017/12/27 16:20:47 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		diff;
	size_t	i;

	diff = 0;
	i = -1;
	while ((++i < n) && !diff)
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
			diff = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
	return (diff);
}
