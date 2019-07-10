/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:14:39 by zwode             #+#    #+#             */
/*   Updated: 2019/04/24 07:49:26 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	p;
	int		u;

	p = ft_strlen(dest);
	u = 0;
	while (src[u] != '\0')
	{
		dest[p + u] = src[u];
		u++;
	}
	dest[p + u] = '\0';
	return (dest);
}
