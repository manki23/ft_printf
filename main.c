/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:01:53 by manki             #+#    #+#             */
/*   Updated: 2019/06/30 15:09:08 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "inc/ft_printf.h"

int		main(int ac, char *av[])
{
	int		r;
	int		rft;
	t_option	opt;
	int		tab[5];

	ac--;
	av++;
	//test 1
	int v = 42;
	char s[] = "popo";
	printf("printf\t\t:");
	opt.minus++;
	r = printf(":%d:\n:%i:\n:%o:\n:%u:\n:%x:\n:%X:\n:%c:\n:%s:\n:%p:\n:%f:\n----------------------------\n", v, v, v, v, v, v, v, s, s, 3.14);
	ft_printf("ft_printf\t:");
	rft = ft_printf(":%d:\n:%i:\n:%o:\n:%u:\n:%x:\n:%X:\n:%c:\n:%s:\n:%p:\n:%f:\n", v, v, v, v, v, v, v, s, s, 3.14);
	printf("r = %d | rft = %d\n", r, rft);
//	printf("r = %d\n", r);
	return (0);
}
