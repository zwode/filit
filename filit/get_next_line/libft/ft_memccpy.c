/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:03:03 by zwode             #+#    #+#             */
/*   Updated: 2019/04/24 03:04:07 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*sour;

	if (!(dst) && !(src))
		return (NULL);
	i = 0;
	dest = (unsigned char*)dst;
	sour = (unsigned char*)src;
	while (i < n)
	{
		dest[i] = sour[i];
		if (sour[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
