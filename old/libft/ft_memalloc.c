/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 10:31:19 by manki             #+#    #+#             */
/*   Updated: 2017/12/27 14:52:40 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*src;
	size_t	i;

	if (!(src = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		*(char *)(src + i) = '\0';
	return (src);
}
