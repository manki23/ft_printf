/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 13:31:46 by manki             #+#    #+#             */
/*   Updated: 2019/07/23 11:42:31 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/ft_printf.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;

	if (size == 0 && ptr)
	{
		ft_memdel(&ptr);
		if (!(ptr = ft_memalloc(1)))
			return (NULL);
	}
	else if (size > 0)
	{
		tmp = ptr;
		if (!(ptr = ft_memalloc(size)))
			return (NULL);
		if (tmp)
		{
			ft_strncpy(ptr, tmp, size);
			ft_memdel(&tmp);
		}
	}
	return (ptr);
}
