/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:01:53 by manki             #+#    #+#             */
/*   Updated: 2019/06/24 15:15:24 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inc/ft_printf.h"

int		main(int ac, char *av[])
{
	int		r;
	int		rft;

	ac--;
	av++;
	//test 1
	printf("printf : ");
	r = printf("Test\n");
	ft_printf("ft_printf : ");
	rft = ft_printf("Test\n");
	printf("r = %d | rft = %d\n", r, rft);
	return (0);
}
