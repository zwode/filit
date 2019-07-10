/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:39:42 by zwode             #+#    #+#             */
/*   Updated: 2019/04/24 04:12:28 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_strtrim_a(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static char			*ft_strtrim_b(char const *s, size_t start, size_t end)
{
	size_t	i;
	char	*g;

	if (!(g = (char*)malloc(end - start + 1)))
		return (NULL);
	i = 0;
	while (start < end)
		g[i++] = s[start++];
	g[i] = '\0';
	return (g);
}

char				*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	start = 0;
	if (end > 0)
	{
		while (s[start] && ft_strtrim_a(s[start]))
			start++;
		if (s[start] == '\0')
			start = end;
		else
		{
			while (--end > 0 && ft_strtrim_a(s[end]))
				(void)0;
			end++;
		}
	}
	return (ft_strtrim_b(s, start, end));
}
