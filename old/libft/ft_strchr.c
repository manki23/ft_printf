/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:46:53 by manki             #+#    #+#             */
/*   Updated: 2017/11/13 11:20:08 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		j;
	int		result;
	char	*ptr;

	result = -1;
	if (c == '\0')
	{
		ptr = (char *)&s[ft_strlen(s)];
		result = 1;
	}
	j = 0;
	while (s[j] && result == -1)
	{
		if (c == s[j])
		{
			ptr = (char *)&s[j];
			result = 1;
		}
		j++;
	}
	if (result == -1)
		return (NULL);
	else
		return (ptr);
}
