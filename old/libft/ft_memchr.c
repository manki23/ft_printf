/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:38:16 by manki             #+#    #+#             */
/*   Updated: 2017/11/12 09:51:21 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;
	int				quit;

	src = (unsigned char *)s;
	quit = 0;
	i = 0;
	while (!quit && i < n)
	{
		if (src[i] == (unsigned char)c)
			quit = 1;
		i++;
	}
	i--;
	if (quit)
		return (&src[i]);
	else
		return (NULL);
}
