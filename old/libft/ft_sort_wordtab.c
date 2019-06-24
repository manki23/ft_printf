/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:47:01 by manki             #+#    #+#             */
/*   Updated: 2017/11/18 15:34:00 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordtablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void			ft_sort_wordtab(char **tab)
{
	int		i;
	int		j;
	char	*aux;

	j = ft_wordtablen(tab);
	while (j > 0)
	{
		i = 0;
		while (i < j - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				aux = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = aux;
			}
			i++;
		}
		j--;
	}
}
