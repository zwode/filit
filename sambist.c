
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
			if (a[i][j] == c)
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
		while (figure[f_i][i] != '\n')
		{
			//if (figure[f_i][i] != '.')
				counter++;
			i++;
		}
		return (counter);
}

/*
int		write_fig(char **map, char **figure, int f_i, int lim, int sdvig)
{
		int j;
		int f;
		int	sdvig;
		int len_cock;
		char *ocko_loop1;

		len_cock = ft_strlen(figure[f_i]);
		sdvig = sdvig;
		j = 0;
		f = 0;
		while (len_cock >= f && sdvig < lim  && (j < lim || figure[f_i][f] == '\n'))
		{
			if (figure[f_i][f] == '.'  && map[sdvig][j] != '.')
			{
				j++;
				f++;
			}
   			//while (map[sdvig][j] != '.' && j < lim)
			//	j++;
			if (figure[f_i][f] == '\n')
			{
				f++; 
				// if (figure[f_i][f] == '.')
				// 	f++;
				sdvig++;
				j = j - param(figure, f_i);
			}
			if (figure[f_i][f] != '\0' && map[sdvig][j] == '.' && j < lim && (figure[f_i][f + 1] == '\n'	|| map[sdvig][j + 1] == '.'))// j + 1 hz, autism
			{
				map[sdvig][j] = figure[f_i][f];
				f++;
			}
			if (j == lim && figure[f_i][f] != '\n')
			{
                f = 0;
				j = -1;
				sdvig++;
			}
			ocko_loop1 = map[sdvig];
			j++;
		}
		if (f == len_cock)
			return (1);
		if (sdvig > lim && f < len_cock)
			return (0);
		if (j <= lim && figure[f_i][f] != '\n')
			return (-1);
	    return (-2);
}
*/



int		write_fig(char **map, char **figure, int f_i, int lim, int sdvig)
{
		int j;
		int f;
		int len_cock;
		char *ocko_loop1;

		len_cock = ft_strlen(figure[f_i]);
		sdvig;
		j = 0;
		f = 0;
		if ((sdvig = vert()) && (j = gor()))
			while (j < lim)
			{
				while (figure[f_i][j] != '\0' && figure[f_i][j] != '\n' && figure[f_i][j])
				{
					map[sdvig][j] = figure[f_i][f];
					j++;
					f++;
				}
			}
		if (f == len_cock)
			return (1);
		if (sdvig > lim && f < len_cock)
			return (0);
		if (j <= lim && figure[f_i][f] != '\n')
			return (-1);
	    return (-2);
}

int		writing_map(char **map, int lim, char **fig, int i, int sdvig)//i eto nomer bukvy; int sdvig = po mape y po ebalu
{
	int 	check;

	check = write_fig(map, fig, i, lim, sdvig);
	print_map(map, lim);
	i++;
	if (!fig[i] && check == 1)
    {
	    print_map(map, lim);
		return (1);
    }
	if (check == 1)
		writing_map(map, lim, fig, i, 0);
	else if(check == -1)
	{
		i--;
		del_last(map, lim, i);
		writing_map(map, lim, fig, i, ++sdvig);
	}
	else if (check == 0)
	{
        i = 0;
		del_all(map, lim + 1);
		writing_map(map, ++lim, fig, i, 0);
	}
	return (1);
}

int		main()
{
    char	        **a;
    char	        **f;
    int		        i;
    int		        j;
	static int		r;

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
	//f[22] = "WW\nWW\n";
    f[1] = ".B\n.B\nBB\n";
	f[0] = "A.\nA.\nAA\n";
	f[2] = "C.\nC.\nCC\n";
    f[3] = "DD\nDD\n";
    f[4] = "EE\nEE\n";
    f[5] = "FF\nFF\n";
    f[6] = "GG\nGG\n";
    f[7] = "HH\nHH\n";
    f[8] = "II\nII\n";
    f[9] = "JJ.\n.JJ\n";
    // f[10] = "KK\nKK\n";
    // f[11] = "LL\nLL\n";
	// f[12] = "MM\nMM\n";
	// f[13] = "NN\nNN\n";
    // f[14] = "OO\nOO\n";
    // f[15] = "PP\nPP\n";
    // f[16] = "QQ\nQQ\n";
    // f[17] = "RR\nRR\n";
    // f[18] = "SS\nSS\n";
    // f[19] = "TT\nTT\n";
    // f[20] = "UU\nUU\n";
    // f[21] = "VV\nVV\n";

	r = 3;
	i = 0;
	writing_map(a, r, f, 0, 0);
	return (4);
}