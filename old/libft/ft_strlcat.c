/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:40:39 by manki             #+#    #+#             */
/*   Updated: 2017/12/28 09:55:18 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		d;
	size_t		s;
	size_t		result;

	if (size > 0)
	{
		d = ft_strlen(dst);
		s = ft_strlen(src);
		result = d + s;
		if (d > size)
			return (s + size);
		s = -1;
		while (src[++s] && ((d + s) < (size - 1)))
			dst[d + s] = src[s];
		dst[d + s] = '\0';
		return (result);
	}
	return (ft_strlen(src));
}
