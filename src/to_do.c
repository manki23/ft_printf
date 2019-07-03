/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:28:10 by manki             #+#    #+#             */
/*   Updated: 2019/07/03 15:04:44 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_fill_p_output(t_option opt, va_list *ap)
{
	void	*arg;

	(void)opt;
	arg = va_arg(*ap, void *);
	return ("(flag %p not done yet)");
}

char	*ft_fill_f_output(t_option opt, va_list *ap)
{
	void	*arg;
//	char	*output;

	(void)opt;
	arg = va_arg(*ap, void *);
	return ("(flag %f not done yet)");
}
