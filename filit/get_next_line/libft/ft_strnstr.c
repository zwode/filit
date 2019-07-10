/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 03:28:48 by zwode             #+#    #+#             */
/*   Updated: 2019/04/23 05:12:57 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t i;
	size_t b;

	i = 0;
	if (((char*)find)[i] == '\0')
		return (((char*)str) + i);
	while (((char*)str)[i] != '\0' && i < len)
	{
		b = 0;
		while (((char)str[i + b] == (char)find[b]
					|| (char)find[b] == '\0') && i + b <= len)
		{
			if (((char*)find)[b] == '\0')
				return (((char*)str) + i);
			b++;
		}
		i++;
	}
	return (0);
}
