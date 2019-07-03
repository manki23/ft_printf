/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:01:53 by manki             #+#    #+#             */
/*   Updated: 2019/07/03 15:35:01 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "inc/ft_printf.h"

#include <limits.h>
#include <float.h>

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
	unsigned long long x = 42;
	r = printf("%-05s|%5.3s|%.10s|%3.6s|%6.0s\n", "toto", "titi", "tata", "tutu", "tete");
	ft_printf("ft_printf\t:");
	rft = ft_printf("%-05s|%5.3s|%.10s|%3.6s|%6.0s\n", "toto", "titi", "tata", "tutu", "tete");
/*	printf("r = %d | rft = %d\n", r, rft);
	printf("CHAR_BIT    :   %d\n", CHAR_BIT);
	printf("CHAR_MAX    :   %d\n", CHAR_MAX);
	printf("CHAR_MIN    :   %d\n", CHAR_MIN);
	printf("INT_MAX     :   %d\n", INT_MAX);
	printf("INT_MIN     :   %d\n", INT_MIN);
	printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
	printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
	printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
	printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
	printf("SHRT_MAX    :   %d\n", SHRT_MAX);
	printf("SHRT_MIN    :   %d\n", SHRT_MIN);
	printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
	printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
	printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
	printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);
*/	//	printf("r = %d\n", r);
	return (0);
}
