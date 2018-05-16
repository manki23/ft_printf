/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:11:12 by manki             #+#    #+#             */
/*   Updated: 2017/11/13 12:21:45 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = 0;
	if ((char *)dst < (char *)src)
	{
		while (i < len)
		{
			*(char *)&dst[i] = *(char *)&src[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			*(char *)&dst[len - 1 - i] = *(char *)&src[len - 1 - i];
			i++;
		}
	}
	return (dst);
}
