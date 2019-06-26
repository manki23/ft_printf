/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:01:53 by manki             #+#    #+#             */
/*   Updated: 2019/06/26 15:07:10 by manki            ###   ########.fr       */
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
	r = printf("%05d:%+10.5d:%.d:%0.d:%.0d:%0.0d\n", -42, 4242, 0, 0, 0, 0);
	ft_printf("ft_printf\t:");
	rft = ft_printf("%05d:%+10.5d:%.d:%0.d:%.0d:%0.0d\n", -42, 4242, 0, 0, 0, 0);
	printf("r = %d | rft = %d\n", r, rft);
//	printf("r = %d\n", r);
	return (0);
}
