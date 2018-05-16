/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:11:46 by manki             #+#    #+#             */
/*   Updated: 2017/11/18 14:32:32 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		ft_swap(int *a, int *b)
{
	int		aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void			ft_sort_integer_table(int *tab, int size)
{
	int		i;
	int		j;

	j = size - 1;
	while (j > 0)
	{
		i = 0;
		while (i < j)
		{
			if (tab[i] > tab[i + 1])
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		j--;
	}
}
