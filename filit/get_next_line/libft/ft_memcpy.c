/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:01:38 by zwode             #+#    #+#             */
/*   Updated: 2019/04/24 03:03:31 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ft_dst;
	char		*ft_src;

	if (!dst && !src)
		return (NULL);
	ft_dst = (char *)dst;
	ft_src = (char *)src;
	while (n)
	{
		*(ft_dst++) = *(ft_src++);
		n--;
	}
	return (dst);
}
