/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:01:53 by manki             #+#    #+#             */
/*   Updated: 2019/07/24 22:14:22 by manki            ###   ########.fr       */
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
	int r1, r2;
	double nb1, nb2, nb3;

	nb1 = 0x1p-1074;
	nb2 = 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
	nb3 = 263.3;
	r1 = ft_printf("%.2147483649f|%2147483649f", 1.0, 1.0);
	ft_printf("\n%f|%-f|%+f|% f|%#f|%0f\n", -0., 0., 0., 0., 0., 0.);
	ft_printf("\n%f", nb3);
	ft_printf("\n|%.1150f|\n|%.1150f|", 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);
	ft_printf("\n------------------------------------------------------\n");
	r2 = dprintf(2, "%.2147483649f|%2147483649f", 1.0, 1.0);
	dprintf(2, "\n%f|%-f|%+f|% f|%#f|%0f\n", -0., 0., 0., 0., 0., 0.);
	dprintf(2, "\n%f", nb3);
	dprintf(2, "\n|%.1150f|\n|%.1150f|", 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);

	double	nb;
	nb = -12547.58;
/*
	   ft_printf("\n------------------------------------------------------\n");
	ft_printf("space:% f\n", nb);
	ft_printf("plus:%+f\n", nb);
	ft_printf("hash:%#f\n", nb);
	ft_printf("precision:%.2f\n", nb);
	ft_printf("big prec:%.14f\n", nb);
	ft_printf("precision + hash:%#.0f\n", nb);
	ft_printf("space + prec:% .5f\n", nb);
	ft_printf("space + prec + hash:%# .0f\n", nb);
	ft_printf("space + prec + hash:% #.0f\n", nb);
	ft_printf("Plus + prec / grande:%+.5f\n", nb);
	ft_printf("Plus + prec / petite:%+.0f\n", nb);
	ft_printf("Plus + prec + hash:%#+.0f\n", nb);
	ft_printf("Prec + 0:%0.5f\n", nb);
	ft_printf("Prec + minus:%-.5f\n", nb);
	ft_printf("size:%5f\n", nb);
	ft_printf("size + space:% 5f\n", nb);
	ft_printf("size + plus:%+5f\n", nb);
	ft_printf("size + space:%# 5f\n", nb);
	ft_printf("size + plus:%#+5f\n", nb);
	ft_printf("size + minus:%-5f\n", nb);
	ft_printf("size + 0:%05f\n", nb);
	ft_printf("size + 0 + plus:%+05f\n", nb);
	ft_printf("size + 0 + plus:%0+5f\n", nb);
	ft_printf("size + 0 + prec:%05.3f\n", nb);
	ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb);
	ft_printf("size + minus + prec:%-5.3f\n", nb);
	ft_printf("size + minus + prec + hash:%-#5.0f\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3f\n", nb);
	ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	ft_printf("size + espace + zero + prec:%0 5.3f\n", nb);
	ft_printf("size + espace + zero + prec:% 05.3f\n", nb);
	ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	ft_printf("size + minus + plus + prec:%-+5.3f\n", nb);
	ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb);
	   ft_printf("\n------------------------------------------------------\n");
	dprintf(2, "space:% f\n", nb);
	dprintf(2, "plus:%+f\n", nb);
	dprintf(2, "hash:%#f\n", nb);
	dprintf(2, "precision:%.2f\n", nb);
	dprintf(2, "big prec:%.14f\n", nb);
	dprintf(2, "precision + hash:%#.0f\n", nb);
	dprintf(2, "space + prec:% .5f\n", nb);
	dprintf(2, "space + prec + hash:%# .0f\n", nb);
	dprintf(2, "space + prec + hash:% #.0f\n", nb);
	dprintf(2, "Plus + prec / grande:%+.5f\n", nb);
	dprintf(2, "Plus + prec / petite:%+.0f\n", nb);
	dprintf(2, "Plus + prec + hash:%#+.0f\n", nb);
	dprintf(2, "Prec + 0:%0.5f\n", nb);
	dprintf(2, "Prec + minus:%-.5f\n", nb);
	dprintf(2, "size:%5f\n", nb);
	dprintf(2, "size + space:% 5f\n", nb);
	dprintf(2, "size + plus:%+5f\n", nb);
	dprintf(2, "size + space:%# 5f\n", nb);
	dprintf(2, "size + plus:%#+5f\n", nb);
	dprintf(2, "size + minus:%-5f\n", nb);
	dprintf(2, "size + 0:%05f\n", nb);
	dprintf(2, "size + 0 + plus:%+05f\n", nb);
	dprintf(2, "size + 0 + plus:%0+5f\n", nb);
	dprintf(2, "size + 0 + prec:%05.3f\n", nb);
	dprintf(2, "size + 0 + prec + hash:%0#5.0f\n", nb);
	dprintf(2, "size + minus + prec:%-5.3f\n", nb);
	dprintf(2, "size + minus + prec + hash:%-#5.0f\n", nb);
	dprintf(2, "size + plus + 0 + prec:%+05.3f\n", nb);
	dprintf(2, "size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	dprintf(2, "size + espace + zero + prec:%0 5.3f\n", nb);
	dprintf(2, "size + espace + zero + prec:% 05.3f\n", nb);
	dprintf(2, "size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	dprintf(2, "size + minus + plus + prec:%-+5.3f\n", nb);
	dprintf(2, "size + minus + plus + prec + hash:%-#+5.0f\n", nb);*/

	/*
	   ft_printf("\n------------------------------------------------------\n");
	   ft_printf("\n------------------------------------------------------\n");
	   ft_printf("\n------------------------------------------------------\n");
	   ft_printf("\n------------------------------------------------------\n");*/
	return (0);
}
