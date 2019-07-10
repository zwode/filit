/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:12:47 by zwode             #+#    #+#             */
/*   Updated: 2019/05/09 15:51:24 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*paw;

	len = 0;
	while (str[len])
		len++;
	paw = (char*)malloc(sizeof(*str) * (len + 1));
	if (paw == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		paw[i] = str[i];
		i++;
	}
	paw[i] = '\0';
	return (paw);
}
