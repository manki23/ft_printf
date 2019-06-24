/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:37:17 by manki             #+#    #+#             */
/*   Updated: 2017/11/18 10:58:59 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_fake(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while ((i < len) && needle[i] && haystack[i] && haystack[i] == needle[i])
		i++;
	if (needle[i])
		return (1);
	else
		return (0);
}

char			*ft_strnstr(const char *haystack, const char *needle, size_t l)
{
	size_t		i;
	size_t		fake;

	fake = 1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while ((i < l) && (fake == 1) && haystack[i])
	{
		if (haystack[i] == needle[0])
			fake = ft_fake(&haystack[i], needle, l - i);
		i++;
	}
	i--;
	if (fake > 0)
		return (NULL);
	else
		return ((char *)&haystack[i]);
}
