/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:16:46 by zwode             #+#    #+#             */
/*   Updated: 2019/07/24 22:37:43 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	fillit(int *argc, char **argv)
{
	t_conf	*conf;

	conf = init_conf();
	if (*argc == 2)
	{
		if ((conf = open_file(argv[1], conf)) != NULL)
		{
			algo(conf);
			ft_print_grid(conf->grid);
			return ;
		}
	}
	ft_putstr("error\n");
}
