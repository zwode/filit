/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 04:18:05 by zwode             #+#    #+#             */
/*   Updated: 2019/04/24 03:21:44 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		probel(char i)
{
	if (i == ' ' || i == '\f' || i == '\t')
		return (1);
	if (i == '\v' || i == '\r' || i == '\n')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int				i;
	unsigned long	b;
	int				sign;

	b = 0;
	sign = 0;
	i = 0;
	while (probel(str[i]))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (b > 9223372036854775807 && sign == 1)
			return (0);
		else if (b > 9223372036854775807 && sign == 0)
			return (-1);
		b = b * 10 + (unsigned long)(str[i++] - '0');
	}
	if (sign == 1)
		return (-b);
	return (b);
}
