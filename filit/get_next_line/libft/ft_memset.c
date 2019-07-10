/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 02:05:54 by zwode             #+#    #+#             */
/*   Updated: 2019/04/24 07:57:07 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *destination, int c, size_t n)
{
	char	*dest;

	if (n == 0)
		return (destination);
	dest = (char *)destination;
	while (n--)
		*dest++ = (unsigned char)c;
	return (destination);
}
