
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

void del_last(char **a, int r, int c)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	c += 'A';
	while (i < r)
	{
		while (j < r)
		{
			if (a[i][j] == c || a[i][j] == '$')
				a[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
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
        {
            a[i][j] = '.';
            j++;
        }
        i++;
        j = 0;
    }
}

int		param(char **figure, int f_i)
{
		int counter;
		int	i;
	
		i = 0;
		counter = 0;
		while (figure[f_i][i] != '\0')
		{
			if (figure[f_i][i] == '\n')
				counter++;
			i++;
		}
		return (counter);
}

int		vert(char **map, char **figure, int f_i, int lim, int sdvig, int sdvig_i)
{
		int slh_n;
		int i;
		int j;
		int counter;
		int f;
		int check;

		check = ft_strlen(figure[f_i]);
		counter = 0;
		f = 0;
		i = sdvig_i;
		j = sdvig;
		slh_n = param(figure, f_i);
		while (slh_n > counter && (j != lim || i != lim))
		{
			if (map[i][j] == '.' || figure[f_i][f] == '.')
			{
				i++;
				counter++;
			}
			else
			{
				j++;
				if (counter < slh_n && counter != 0 && j != lim && map[i][j] != '.')
				{
					if ((j + 1) == lim && (i + 1) == lim)
						return (0);
					i = 0;
					counter = 0;
					
				}
				if (j == lim)
				{
					i++;
					j = 0;
				}
			}
			while (figure[f_i][f] != '\n' && figure[f_i][f] != '\0')
				f++;
			if (check > f)
				f++;
			if (f == check)
				f = 0;
		}
		if (counter == slh_n && lim >= i)
		{
			i -= counter;
			if (map[i][j] == '.')
				map[i][j] = '$';
			return (1);
		}
		return (0);
}

int		gor(char **map, char **figure, int f_i, int lim)
{
		int i;
		int j;
		int j_tmp;
		int j_max;
		int counter;
		int f;

		f = 0;
		j_tmp = 0;
		counter = 0;
		j = 0;
		j_max = 0;
		while (figure[f_i][j] != '\0')
		{
			while (figure[f_i][j] != '\n')
			{
				j++;
				j_tmp++;
			}
			if (j_max < j_tmp)
				j_max = j_tmp;
			j_tmp = 0;
			j++;
		}
		i = 0;
		j = 0;
		while (map[i][j] != '$' && i < lim)
		{
			while (map[i][j] != '$' && map[i][j] != '\0' && j < lim)
				j++;
			if (j == lim)
			{
				i++;
				j = 0;
			}
		}
		if (i == lim)
			return (-1);
		while (counter < param(figure, f_i))
		{
			j -= j_tmp;
			j_tmp = 0;
			while (j_tmp < j_max)//
			{
				if (((map[i][j] != '.' && map[i][j] != '$') || j >= lim) && figure[f_i][f] != '.')
					return (-1);
				j++;
				j_tmp++;
				f++;
			}
			f++;
			counter++;
			i++;
		}
		return (1);
}

int		write_fig(char **map, char **figure, int f_i, int lim, int sdvig_j, int sdvig_i)
{
	int 	j;
	int 	f;
	int 	check_point;
	int 	len_cock;//??
	//char 	*ocko_loop1;
	int 	i;

	i = 0;
	j = 0;
	check_point = 0;
	if (!figure[f_i])
		return (1);
	len_cock = ft_strlen(figure[f_i]);
	if (vert(map, figure, f_i, lim, sdvig_j, sdvig_i))
	{
		if (gor(map, figure, f_i, lim) == -1)
			return (-1);
	}
	else
		return (0);
	f = 0;
	while (map[i][j] != '$' && i < lim)
	{
		while (map[i][j] != '$' && map[i][j] != '\0' && j < lim)
			j++;
		if (j == lim)
		{
			i++;
			j = 0;
		}
	}
	while (i <= lim && figure[f_i][f] != '\0')
	{
		while (figure[f_i][f] != '\0' && figure[f_i][f] != '\n' && figure[f_i][f] && j < lim && (map[i][j] == '.' || map[i][j] == '$' || figure[f_i][f] == '.'))
		{
			if (figure[f_i][f] != '.' || figure[f_i][f] == '$')
				map[i][j] = figure[f_i][f];
			check_point++;
			j++;
			f++;
		}
		i++;
		j -= check_point;
		check_point = 0;
		if (figure[f_i][f] == '\n')
			f++;
	}
	if (f >= len_cock)
		return (1);
	if (i > lim && f < len_cock)
		return (0);
	if (j <= lim && figure[f_i][f] != '\n')
		return (-1);
	return (1);
}

int		writing_map(char **map, int lim, char **fig, int i, int sdvig_j, int sdvig_i)//i eto nomer bukvy; int sdvig = po mape y po ebalu
{
	int 	check;

	check = write_fig(map, fig, i, lim, sdvig_j, sdvig_i);
	i++;
	print_map(map, lim);
	if (!fig[i] && check == 1)
    {
		return (1);
    }
	if (check == 1)
		writing_map(map, lim, fig, i, 0, 0);
	else if(check == -1)
	{
		i--;
		del_last(map, lim, i);
		if (sdvig_j == lim - 1)
		{
			sdvig_j = -1;
			sdvig_i++;
		}
		writing_map(map, lim, fig, i, ++sdvig_j, sdvig_i);
	}
	else if (check == 0)
	{
        i = 0;
		del_all(map, lim + 1);
		writing_map(map, ++lim, fig, i, 0, 0);
	}
	return (1);
}

int		main()
{
    char	**a;
    char	**f;
    int		i;
    int		j;
	int		r;

	a = malloc(sizeof(*a)*12);
	i = 0;
	while (i < 12)
		a[i++] = ft_strnew(12);
	i = 0;
	while (i < 12)
	{
		j = 0;
		while (j < 12)
			a[i][j++] = '.';
		i++;
	}
	f = malloc(sizeof(*a)*2);
	f[0] = ".AA\nAA.\n";
    f[1] = "BB\n.B\n.B\n";
	f[2] = ".CC\nCC.\n";
	f[3] = ".DD\nDD.\n";
    f[4] = ".EE\nEE.\n";
    f[5] = ".FF\nFF.\n";
    f[6] = ".GG\nGG.\n";
    f[7] = ".HH\nHH.\n";
    // f[8] = "II\nII\n";
    // f[9] = "JJ\nJJ\n";
    // f[10] = "KK\nKK\n";
    // f[11] = "LL\nLL\n";
	// f[12] = "MM\nMM\n";
	// f[13] = "NN\nNN\n";
    // f[14] = "OO\nOO\n";
    // f[15] = "PP\nPP\n";
    // f[16] = "QQ\nQQ\n";
    // f[17] = "RR\nRR\n";
    // f[18] = "SS\nSS\n";
    // f[19] = "TT.\n.TT\n";
    // f[20] = "UU.\n.UU\n";
    // f[21] = "VV.\n.VV\n";
	// f[22] = "WW.\n.WW\n";
	
	r = 0;
	while (f[r])
		r++;
	j = r*4;
	r = 0;
	while ((r*r) < j)
		r++;
	writing_map(a, r, f, 0, 0, 0);
	return (4);
}
