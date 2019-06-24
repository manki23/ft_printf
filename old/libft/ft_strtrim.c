/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:03:07 by manki             #+#    #+#             */
/*   Updated: 2017/12/27 15:42:47 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_counttrim(const char *s)
{
	int		i;
	int		j;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (0);
	j = 0;
	while (s[i])
	{
		i++;
		j++;
	}
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		j--;
		i--;
	}
	return (j);
}

char		*ft_strtrim(char const *s)
{
	char	*fresh;
	int		i;
	int		j;

	if (!s || !(fresh = (char *)malloc(sizeof(char) * (ft_counttrim(s) + 1))))
		return (NULL);
	j = 0;
	if (ft_counttrim(s) > 0)
	{
		i = 0;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		j = -1;
		while (++j < ft_counttrim(s))
			fresh[j] = s[i + j];
	}
	fresh[j] = '\0';
	return (fresh);
}
