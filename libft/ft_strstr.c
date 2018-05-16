/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:17:43 by manki             #+#    #+#             */
/*   Updated: 2017/11/19 11:28:39 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fake(const char *haystack, const char *needle)
{
	int		i;

	i = 0;
	while (needle[i] && haystack[i] && haystack[i] == needle[i])
		i++;
	if (needle[i])
		return (1);
	else
		return (0);
}

char		*ft_strstr(const char *haystack, const char *needle)
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
