/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:11:24 by manki             #+#    #+#             */
/*   Updated: 2019/07/10 17:21:42 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char			*ft_fill_f_output(t_option opt, va_list *ap, size_t *size)
{
	double		arg;
	char		*output;

	(void)opt.precision;
	arg = va_arg(*ap, double);
	output = ft_strjoin("un", "done");
	size[0] = ft_strlen(output);
	return (output);
}
