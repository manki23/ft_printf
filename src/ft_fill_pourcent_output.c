/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pourcent_output.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:25:49 by manki             #+#    #+#             */
/*   Updated: 2019/07/03 14:23:23 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_fill_output(t_option opt)
{
	char	*output;

	if (opt.width > 1)
	{
		output = ft_strnew(opt.width - 1);
		ft_memset(output, ' ', opt.width - 1);
		if (opt.zero && !opt.minus)
			ft_tr(output, ' ', '0');
		if (opt.minus)
			output = ft_strjoin("%", output);
		else
			output = ft_strjoin(output, "%");
	}
	else
		output = "%";
	return (output);
}

char			*ft_fill_pourcent_output(t_option opt, va_list *ap)
{
	char	*output;

	(void)ap;
	output = ft_fill_output(opt);
	return (output);
}
