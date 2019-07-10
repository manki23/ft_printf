/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:57:01 by manki             #+#    #+#             */
/*   Updated: 2019/07/09 17:58:32 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char *str)
{
	int			i;
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= '\a' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i++] - '0';
	}
	return (res * sign);
}
