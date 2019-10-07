/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:16:46 by zwode             #+#    #+#             */
/*   Updated: 2019/07/24 22:37:55 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_conf	*open_file(char *file, t_conf *conf)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if ((conf = read_file(&fd, conf)) == 0)
		return (NULL);
	return (conf);
}

t_conf	*read_file(int *fd, t_conf *conf)
{
	char	*buff;
	int		i;
	t_tris	*tris;
	int		last_read;
	int		now_read;

	i = 0;
	last_read = -1;
	buff = ft_strnew(21);
	while ((now_read = read(*fd, buff, 21)))
	{
		last_read = now_read;
		tris = create_tris(buff, i);
		if (tris == NULL)
			return (NULL);
		conf->nbr_piece = i + 1;
		conf->list_tris[i] = *tris;
		i++;
	}
	if (last_read != 20 || now_read != 0)
		return (NULL);
	return (conf);
}
