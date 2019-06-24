/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:17:35 by manki             #+#    #+#             */
/*   Updated: 2017/11/12 09:26:14 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;
	int				quit;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	quit = 0;
	i = 0;
	while (!quit && i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			quit = 1;
		i++;
	}
	if (quit)
		return (&dst[i]);
	else
		return (NULL);
}
