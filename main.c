/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:45:26 by zwode             #+#    #+#             */
/*   Updated: 2019/06/25 02:01:42 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int				main(int argc, char **argv)
{
	int			id_tetr;
	int			fd;
	char		*tetr;

	id_tetr = 0;
	fd = open(argv[1], O_RDONLY);
	argc = argc - 1;
	while (get_next_line(fd, &tetr) > 0)
	{
		if (valid(tetr) >= 1 || tetr[0] == '\n')
		{
			id_tetr++;
			ft_putstr("+\n");
		}
		else
		{
			ft_putstr("Invalid, please cheak your tetromin\n");
		}
		if (id_tetr == 4)
		{
			ft_putstr("Valid\n");
			id_tetr = 0;
		}
	}
	if (id_tetr == 4)
		ft_putstr("Work");
	else
		ft_putstr("Error");
	return (0);
}
