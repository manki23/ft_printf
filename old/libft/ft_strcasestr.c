/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 10:09:03 by manki             #+#    #+#             */
/*   Updated: 2017/11/19 11:40:02 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_fake(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && ft_tolower((char)s1[i]) == ft_tolower((char)s2[i]))
		i++;
	if (s2[i])
		return (1);
	else
		return (0);
}

char			*ft_strcasestr(const char *haystack, const char *needle)
{
	int		i;
	int		res;

	i = 0;
	res = 1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		res = 2;
	while (haystack[i] && (res == 1))
	{
		if (haystack[i] == needle[0])
			res = ft_fake(&haystack[i], needle);
		i++;
	}
	i--;
	if (res > 0)
		return (NULL);
	else
		return ((char *)&haystack[i]);
}
