/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:01:53 by manki             #+#    #+#             */
/*   Updated: 2019/06/27 17:07:33 by manki            ###   ########.fr       */
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
	printf("printf\t\t:");
	opt.minus++;
	r = printf("%o:%o:%o:%o:%o:%o:%o\n", 1073741824, 2147483648, -8, -1, -2147483647, 10, -42);
	ft_printf("ft_printf\t:");
	rft = ft_printf("%o:%o:%o:%o:%o:%o:%o\n", 0, -1, 8, 4, 16, 10, -42);
	printf("r = %d | rft = %d\n", r, rft);
	ft_printf(ft_itoa_base(1073741824, "01234567"));
	ft_printf(":");
	ft_printf(ft_itoa_base(2147483648, "01234567"));
	ft_printf(":");
	ft_printf(ft_itoa_base(-8, "01234567"));
	ft_printf(":");
	ft_printf(ft_itoa_base(-1, "01234567"));
	ft_printf(":");
	ft_printf(ft_itoa_base(-2147483648, "01234567"));
	ft_printf(":");
	ft_printf(ft_itoa_base(10, "01234567"));
	ft_printf(":");
	ft_printf(ft_itoa_base(-42, "01234567"));
	ft_printf("\n");
//	printf("r = %d\n", r);
	return (0);
}
