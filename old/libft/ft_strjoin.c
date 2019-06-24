/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:48:54 by manki             #+#    #+#             */
/*   Updated: 2017/11/12 13:00:35 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;
	int		j;

	if (!s1 || !s2 || !(fresh = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
	ft_strlen(s2) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		fresh[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		fresh[i] = s2[j];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
