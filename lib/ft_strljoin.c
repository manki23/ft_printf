/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:48:54 by manki             #+#    #+#             */
/*   Updated: 2019/07/19 12:45:42 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_strljoin(char const *s1, char const *s2, int s1_len, int s2_len)
{
	char	*fresh;
	int		i;
	int		j;

	if (!s1 || !s2 || !(fresh = (char *)malloc(sizeof(char) * (s1_len + s2_len
						+ 1))))
		return (NULL);
	i = -1;
	while (++i < s1_len)
		fresh[i] = s1[i];
	j = -1;
	while (++j < s2_len)
	{
		fresh[i] = s2[j];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
