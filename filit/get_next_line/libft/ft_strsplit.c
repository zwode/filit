/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:40:29 by zwode             #+#    #+#             */
/*   Updated: 2019/04/24 04:12:44 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	th_april(const char *s, char c)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (*s != '\0')
	{
		if (a == 1 && *s == c)
			a = 0;
		if (a == 0 && *s != c)
		{
			a = 1;
			b++;
		}
		s++;
	}
	return (b);
}

static int	avengers_end_game(const char *s, char c)
{
	int		p;

	p = 0;
	while (*s != c && *s != '\0')
	{
		p++;
		s++;
	}
	return (p);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**u;
	int		n;
	int		i;

	i = 0;
	n = th_april((const char*)s, c);
	u = (char**)malloc(sizeof(*u) * (th_april((const char *)s, c) + 1));
	if (u == NULL)
		return (NULL);
	while (n--)
	{
		while (*s == c && *s != '\0')
			s++;
		u[i] = ft_strsub((const char*)s, 0,
				avengers_end_game((const char*)s, c));
		if (u[i] == NULL)
			return (NULL);
		s = s + avengers_end_game(s, c);
		i++;
	}
	u[i] = NULL;
	return (u);
}
