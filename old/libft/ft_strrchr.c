/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:06:20 by manki             #+#    #+#             */
/*   Updated: 2017/11/11 12:16:53 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	int		result;

	i = 0;
	result = -1;
	while (s[i])
	{
		if (s[i] == c)
		{
			ptr = (char *)&s[i];
			result = 1;
		}
		i++;
	}
	if (c == '\0')
	{
		ptr = (char *)&s[i];
		result = 1;
	}
	if (result == -1)
		return (NULL);
	else
		return (ptr);
}
