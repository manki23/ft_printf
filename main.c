/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:01:53 by manki             #+#    #+#             */
/*   Updated: 2019/07/13 13:32:08 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "inc/ft_printf.h"

#include <limits.h>
#include <float.h>
#include <math.h>

/*
   ft_printf("------------------------------------------------------\n");
   */
int		main(int ac, char *av[])
{
	ac--;
	av++;

	long double	nb;
	//nb = -8965421.12356432156;
	nb = LDBL_MAX;
	//nb = M_PI;

	ft_printf("big prec:%.20Lf\n", nb);
/*	ft_printf("size + 0 + prec:%05.3Lf\n", nb);
	ft_printf("size + minus + prec:%-5.3Lf\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3Lf\n", nb);
	ft_printf("size + espace + zero + prec:%0 5.3Lf\n", nb);
	ft_printf("size + espace + zero + prec:% 05.3Lf\n", nb);
	ft_printf("size + minus + plus + prec:%-+5.3Lf\n", nb);*/
   ft_printf("------------------------------------------------------\n");

	dprintf(2, "big prec:%.20Lf\n", nb);
/*	dprintf(2, "size + 0 + prec:%05.3Lf\n", nb);
	dprintf(2, "size + minus + prec:%-5.3Lf\n", nb);
	dprintf(2, "size + plus + 0 + prec:%+05.3Lf\n", nb);
	dprintf(2, "size + espace + zero + prec:%0 5.3Lf\n", nb);
	dprintf(2, "size + espace + zero + prec:% 05.3Lf\n", nb);
	dprintf(2, "size + minus + plus + prec:%-+5.3Lf\n", nb);
*/
	return (0);
}
