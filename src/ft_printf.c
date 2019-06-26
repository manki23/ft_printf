/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:00:08 by manki             #+#    #+#             */
/*   Updated: 2019/06/26 15:11:28 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_strlentoc(const char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	int		ret;
	char	*ptr;
	char	*ptr2;
	char	*output;

	ret = ft_strlen(format);
	if (ret > 0)
	{
		if (!(ptr = ft_strchr(format, '%')))
			ft_putstr(format);
		else
		{
			//creation de la chaine output dans la memoire et remplissage
			//jusqu au premier '%'
			if (!(output = ft_strnew(ft_strlentoc(format, '%'))) ||
					!(output = ft_strsub(format, 0, ft_strlentoc(format, '%'))))
				return (-1);
			/*
			 *traitement du %
			 * on recupere la chaine a partir du %
			 *il faut analyser ce qu'on a apres : la conversion et ses options
			 * 1 fonction analyse de conversion
			 * 1 fonction analyse d options
			 * il faut fournir a la fonction l'argument correspondant
			 * retourner le texte a ajouter a output et modifier ptr pour le 
			 * faire pointer sur le caractere suivant la conversion qui vient 
			 * d etre analysee
			 */
			va_start(ap, format);
			//tant qu'il y a des conversions a faire:
			while (ptr && ptr[0] == '%')
			{
				// ajout de la conversion a l output, ptr pointe sur le texte
				// suivant celle-ci.
				if (!(output = ft_strjoin(output, ft_conv(&ptr, &ap))))
					return (-1);
				//on fait pointer ptr2 sur la prochaine conversion a faire
				//si ptr2 pointe sur null, il n'y a plus de conversions a faire
				//on recupere donc la fin du texte et on sort du while
				//si ptr2 non null  on recupere le texte entre ces deux 
				//conversions.
				if (!(ptr2 = ft_strchr(ptr, '%')))
					output = ft_strjoin(output, ptr);
				else
					output = ft_strjoin(output, ft_strsub(ptr, 0, ft_strlen(ptr)
								- ft_strlen(ptr2)));
					ptr = ptr2;
			}
			va_end(ap);
			ret = ft_strlen(output);
			ft_putstr(output);
		}
	}
	return (ret);
}

/*
   ft_putstr("***\n");
   ft_putstr(format);
   ft_putstr("***\n");
   */
