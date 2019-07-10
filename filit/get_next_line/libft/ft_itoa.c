/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 02:09:52 by zwode             #+#    #+#             */
/*   Updated: 2019/04/24 04:13:12 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_string(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (2);
	if (n == -2147483648)
	{
		count = count + 2;
		n = 147483648;
	}
	else if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	if (n <= 0)
		count++;
	return (count);
}

char		*ft_itoa(int n)
{
	int				i;
	char			*tab;

	i = count_string(n) - 1;
	if (!(tab = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n < 0)
		tab[0] = '-';
	if (n == -2147483648)
	{
		tab[1] = '2';
		n = 147483648;
	}
	else if (n < 0)
		n = -n;
	tab[i--] = '\0';
	if (n == 0)
		tab[i] = '0';
	while (n != 0)
	{
		tab[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (tab);
}
