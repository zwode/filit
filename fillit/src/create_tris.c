/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:16:46 by zwode             #+#    #+#             */
/*   Updated: 2019/07/24 22:37:38 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_tris	*init_tris(char name)
{
	t_tris	*tris;
	t_point	*coord;
	int		i;

	i = -1;
	tris = (t_tris*)malloc(sizeof(t_tris));
	tris->name = name + 65;
	while (++i < 4)
	{
		coord = (t_point*)malloc(sizeof(t_point));
		coord->x = -1;
		coord->y = -1;
		tris->coord[i] = *coord;
	}
	return (tris);
}

t_tris	*create_tris(char *str, char name)
{
	t_tris	*tris;
	int		i;
	int		nbr;

	i = -1;
	nbr = -1;
	tris = init_tris(name);
	while (++i < 20)
	{
		if (str[i] == '\n' && (i + 1) % 5 != 0)
			return (NULL);
		if (str[i] == '.' || str[i] == '\n')
			;
		else if (str[i] == '#' && ++nbr < 4)
			create_tris_coord(tris, nbr, i);
		else
			return (NULL);
	}
	if (name != 0 && str[i] != '\n')
		return (NULL);
	return (check_tris(tris));
}

void	create_tris_coord(t_tris *tris, int nbr, int i)
{
	t_point		point;

	point = *ft_new_point(i % 5, i / 5);
	tris->coord[nbr] = point;
}
