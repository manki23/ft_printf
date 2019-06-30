/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:28:10 by manki             #+#    #+#             */
/*   Updated: 2019/06/30 16:05:05 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_fill_u_output(t_option opt, va_list *ap)
{
	unsigned int	arg;
	char			*output;

	(void)opt;
	arg = va_arg(*ap, unsigned int);
	output = ft_strjoin(ft_itoa((int)arg), "(flag %u not done yet)");
	return (output);
}

char	*ft_fill_o_output(t_option opt, va_list *ap)
{
	unsigned int	arg;
	char			*output;

	(void)opt;
	arg = va_arg(*ap, unsigned int);
	output = ft_strjoin(ft_itoa_base((int)arg, "01234567"), "(flag %o not done yet)");
	return (output);
}

char	*ft_fill_x_output(t_option opt, va_list *ap)
{
	unsigned int	arg;
	char			*output;

	(void)opt;
	arg = va_arg(*ap, unsigned int);
	output = ft_strjoin(ft_itoa_base((int)arg, "0123456789abcdef"), "(flag %x not done yet)");
	return (output);
}

char	*ft_fill_pourcent_output(t_option opt, va_list *ap)
{
	char	*output;

	(void)opt;
	(void)ap;
	output = ft_strjoin("%", "(flag % not done yet)");
	return (output);
}

char	*ft_fill_c_output(t_option opt, va_list *ap)
{
	char	arg;
	char	tmp[2];
	char	*output;

	(void)opt;
	arg = va_arg(*ap, int);
	tmp[0] = arg;
	tmp[1] = '\0';
	output = ft_strjoin(tmp, "(flag %c not done yet)");
	return (output);
}

char	*ft_fill_s_output(t_option opt, va_list *ap)
{
	char	*arg;
	char	*output;

	(void)opt;
	arg = va_arg(*ap, char *);
	output = ft_strjoin(arg, "(flag %s not done yet)");
	return (output);
}

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
