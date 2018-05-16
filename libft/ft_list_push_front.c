/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 12:40:41 by manki             #+#    #+#             */
/*   Updated: 2017/12/28 10:17:52 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **list, void const *content, size_t c_size)
{
	t_list		*tmp;
	t_list		*list_copy;

	tmp = ft_lstnew(content, c_size);
	if (list && tmp)
	{
		list_copy = *list;
		tmp->next = list_copy;
		*list = tmp;
	}
}
