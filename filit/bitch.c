/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <zwode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:41:06 by zwode             #+#    #+#             */
/*   Updated: 2019/07/09 22:21:24 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filit.h"

void	print_map(char **a, int r)
{
	size_t i;
	
	i = 0;
	while (i < r)
	{
		if (i == 0)
			write(1, "\n", 1);
		write(1, a[i], r);
		write(1, "\n", 1);
		i++;
	}
}

void del_last(char **a, char **f, int r)
{
	int i;
	int j;
	int b;

	i = 0;
	j = 0;
	while (f[i][j] == '.')
		j++;
	b = f[i][j];
	i = 0;
	j = 0;
	while (i < r)
	{
		while (j < r)
		{
			if (a[i][j] == b)
				a[i][j] = '.';
			j++;
		}
		i++;
	}
	print_map(a, r);
}

void    del_all(char **a, int r)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < r)
    {
        while(j < r)
            a[i][j++] = '.';
        i++;
        j = 0;
    }
	print_map(a, r);
}

int		writing(char **a, int r, char **f, int i, int j)
{
	int i_m = 0;
	int j_m = 0;
	int i_f = 0;
	int j_f = 0;
	
	while (i_m + i < r)
	{
		while (j_m + j < r && f[i_f][j_f] != '\n' && f[i_f][j_f])
		{
			if (a[i_m + i][j_m + j] == '.' && f[i_f][j_f])//esli "." na map, a v fig net, to zapolnaem
			{
				a[i_m + i][j_m + j] = f[i_f][j_f];
				j_m++;
				j_f++;
				if ((j_m + j == r) && (f[i_f][j_f] != '\n'))
				{
                    if (i_m == r && f[i_f][j_f])
                    {
                        del_all(a, r);
					    writing(a, ++r, f, 0, 0);
                    }
                    else
                    {
					    del_last(a, f, r);
					    writing(a, r, f, ++i, j);
                    }
                    print_map(a, r);
				}
			}
			else if (a[i_m + i][j_m + j] != '.' && f[i_f][j_f] == '.')//esli i na map i v figure "."
			{
				j_m++;			
				j_f++;
			}
			else //esli na map ne "."
				j_m++;
		}
		if (f[i_f][j_f] == '\n')
			j_f++;
		if (!f[i_f][j_f])
			i_f++;
		j_m = 0;
		i_m++;
	}
	return (0);
}

int		main()
{
	char	**a;
	char	**f;
	int		i;
	int		j;
	int		r;

	a = malloc(sizeof(*a)*10);
	i = 0;
	while (i < 10)
		a[i++] = ft_strnew(10);
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
			a[i][j++] = '.';
		i++;
	}
	f = malloc(sizeof(*a)*2);
	f[0] = "AA\nA.\nA.\n";
	f[1] = "BB\nBB\n";
	f[2] = "CCCC\n";
	r = 3;
	i = 0;
	print_map(a, r);
	writing(a, r, f, 0, 0);
	//writing(a, r, &f[1], 0, 0);
	//writing(a, r, &f[2], 0, 0);
	return (0);
}