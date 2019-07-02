/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:01:53 by manki             #+#    #+#             */
/*   Updated: 2019/07/02 20:32:08 by manki            ###   ########.fr       */
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
	long long v = -42;
	char s[] = "popo";
	printf("printf\t\t:");
	opt.minus++;
	r = printf("%hhu\n", -42);
	ft_printf("ft_printf\t:");
	rft = ft_printf("%hhu\n", -42);
	printf("r = %d | rft = %d\n", r, rft);
//	printf("r = %d\n", r);
	return (0);
}
