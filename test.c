/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:54:12 by manki             #+#    #+#             */
/*   Updated: 2018/05/16 14:37:14 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char * restrict format, ...);

int		main(void)
{
	//printf("basic\ninput\n");
	ft_printf("basic %d input\n", 1, 2, 3);
	return (0);
}
