/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:01:53 by manki             #+#    #+#             */
/*   Updated: 2019/07/31 09:58:17 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "inc/ft_printf.h"

#include <limits.h>
#include <float.h>
#include <math.h>

int		main(void)
{
	long double nb1, nb2, nb3;
	int			r1, r2;

	//nb1 = LDBL_MAX;
	nb1 = 2.2;
	nb2 = 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
	nb3 = 263.3;
	//ft_printf("%Lf\n", LDBL_MAX);
	printf("[%s|%s]", "toto", 6);

	//dprintf(2, "%s\n\n", ans);
	////dprintf(2,		"%s\n\n", cor);
	//exit(FAILURE);
	//}
	//	

		/*
		   ft_printf("\n------------------------------------------------------\n");
		   ft_printf("\n------------------------------------------------------\n");
		   ft_printf("\n------------------------------------------------------\n");
		   ft_printf("\n------------------------------------------------------\n");
		   ft_printf("\n------------------------------------------------------\n");*/
		return (0);
		}
