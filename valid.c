/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 02:01:57 by zwode             #+#    #+#             */
/*   Updated: 2019/06/25 04:57:23 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int				all_valid_counter(char *tetr, int b, int c, int cheak)
{
	int			i;

	i = 0;
	if (c > 4)
		return (-1);
	if (b == 0 && c == 0 && cheak == 1)
		return (1);
	if (b == 3 || b == 4)
		return (0);
	if (b == 6)
	{
		while (tetr[i] == '.' || tetr[i] == '#')
			i++;
		if (i > 4 || i < 4)
			return (1);
	}
	return (0);
}

int				tetr_valid_counter_start(char *tetr)
{
	int			i;

	i = 0;
	while (tetr[i] != '\n' && tetr[i] != '\0' && tetr[i] != '#')
		i++;
	return (i);
}

int				tetr_valid_counter_end(char *tetr)
{
	int			i;

	i = 0;
	while (tetr[i] != '\n' && tetr[i] != '\0')
		i++;
	while (tetr[i] != '#' && i != -1)
		i--;
	if (i == -1)
		return (4);
	return (i);
}

int				counter_tetr(char *tetr)
{
	int			i;
	int			counter;

	i = 4;
	counter = 0;
	while (i >= 0)
	{
		if (tetr[i] == '#')
			counter++;
		i--;
	}
	return (counter);
}

int				valid(char *tetr)
{
	static	int	id_tetr[7];

	if (all_valid_counter(tetr, 6, 0, 0) == 1)
		return (0);
	if (id_tetr[2] == 0)
	{
		id_tetr[0] = tetr_valid_counter_start(tetr);
		id_tetr[1] = tetr_valid_counter_end(tetr);
	}
	id_tetr[5] = tetr_valid_counter_start(tetr);
	id_tetr[6] = tetr_valid_counter_end(tetr);
	char start = '0' + tetr_valid_counter_start(tetr);
	char end = '0' + tetr_valid_counter_end(tetr);
	ft_putchar(start);
	ft_putchar(end);
	if (id_tetr[0] >= id_tetr[5] && id_tetr[1] <= id_tetr[6])
		id_tetr[4] = 1;
	id_tetr[0] = id_tetr[5];
	id_tetr[1] = id_tetr[6];
	id_tetr[3] = id_tetr[3] + counter_tetr(tetr);
	id_tetr[2]++;
	if (id_tetr[2] <= 4 && id_tetr[3] == 4)
		id_tetr[4] = 1;
	if (id_tetr[2] == 4 && id_tetr[3] == 4)
		id_tetr[3] = 0;
	if (id_tetr[2] == 4)
		id_tetr[2] = 0;
	return (id_tetr[4] + all_valid_counter(tetr, id_tetr[2], id_tetr[3], 1));
}
