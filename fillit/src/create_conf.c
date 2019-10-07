/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_conf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:16:46 by zwode             #+#    #+#             */
/*   Updated: 2019/07/24 22:37:34 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_conf	*init_conf(void)
{
	t_conf	*conf;

	conf = (t_conf*)malloc(sizeof(t_conf));
	return (conf);
}
