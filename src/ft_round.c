/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:46:22 by manki             #+#    #+#             */
/*   Updated: 2019/07/29 14:46:27 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_byte	ft_rounding(char *nb, int *j, int *overflow)
{
	if (nb[*j] == '9')
	{
		nb[*j] = '0';
		if (*j == 0)
			overflow[0] = 1;
	}
	else if (nb[*j] != '.')
	{
		nb[*j] += 1;
		j[0] = 0;
	}
	j[0]--;
	return (0);
}

static char		*ft_dotfive(char *nb, int dot_pos, int *overflow)
{
	int		i;
	int		add;

	i = dot_pos + 1;
	add = 0;
	while (nb[++i] && !add)
	{
		if (nb[i] > '0')
			add = 1;
	}
	if (nb[i] == '\0' && ((nb[dot_pos - 1] - '0') % 2))
		add = 1;
	i = dot_pos - 1;
	while (add && i >= 0 && nb[i] == '9')
	{
		nb[i] = '0';
		i--;
	}
	if (i != -1)
		nb[i] += add;
	else
		overflow[0] = 1;
	return (nb);
}

static char		*ft_nodotfive(char *nb, int pos, int *overflow)
{
	int		i;
	int		j;

	i = pos + 1;
	while (nb[i] == '5' || nb[i] == '.')
		i++;
	if (nb[i] && nb[i] > '5' && nb[pos] < '9' && nb[pos] != '.')
	{
		if (nb[pos] == '.')
			nb[pos - 1] += 1;
		else
			nb[pos] += 1;
	}
	else if (nb[i] && (nb[i] > '5'))
	{
		j = pos;
		while (j >= 0)
			ft_rounding(nb, &j, overflow);
	}
	return (nb);
}

char			*ft_roundd(char *nb, int pos, int *dot_pos, int precision)
{
	int		overflow;

	overflow = 0;
	if (nb[pos] == '.' && nb[pos + 1] == '5' && precision == 0)
		nb = ft_dotfive(nb, dot_pos[0], &overflow);
	else
		nb = ft_nodotfive(nb, pos, &overflow);
	nb[pos + 1] = '\0';
	if (overflow)
		nb = ft_charcat('1', nb, pos + 1);
	dot_pos[0] += overflow;
	return (nb);
}
