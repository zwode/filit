/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:16:46 by zwode             #+#    #+#             */
/*   Updated: 2019/07/24 22:37:25 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		brain_rec(t_conf *conf, t_point *pos, char **grid, int iter)
{
	if (iter == conf->nbr_piece)
		return (1);
	if (pos->x < 0)
		return (0);
	if (ft_is_putable(grid, pos, &conf->list_tris[iter]))
	{
		ft_put_piece(grid, pos, &conf->list_tris[iter]);
		if (brain_rec(conf, ft_new_point(0, 0), grid, iter + 1))
			return (1);
		ft_clean_grid(grid, conf->list_tris[iter].name);
	}
	return (brain_rec(conf, ft_give_next_point(pos, grid), grid, iter));
}

void	algo(t_conf *conf)
{
	char	**grid;
	t_point	*pos;

	pos = ft_new_point(0, 0);
	conf->min_size = 2;
	grid = ft_new_grid(conf->min_size);
	while (!(brain_rec(conf, pos, grid, 0)))
	{
		conf->min_size++;
		grid = ft_new_grid(conf->min_size);
	}
	conf->grid = ft_copy_grid(grid, conf->min_size);
}
