#include "filit.h"


// int     writing_map(char **map, int lim, char **fig, int bukva, int j) //i kol figur, j sdvig po ebalu
// {
//         int m_i;
//         int m_j;
//         int f_i;
//         int f_j;
// 		int check;

//         m_i = 0;
//         m_j = 0;
//         f_i = 0;
//         f_j = 0;
//         if (m_i + bukva < lim)
//         {
//             if (m_j + j < lim && fig[f_i][f_j])
//             {
// 				check = write_fig(map, fig, f_i, lim, j);
// 				print_map(map, lim);
// 				bukva++;
//                 if (check == 1)
// 				{
// 					f_i++;
// 					writing_map(map, lim, fig, bukva, 0);
// 				}
// 				else if (check == -1)
// 				{
// 					bukva--;
// 					del_last(map, lim, bukva);//i nomer bykvi
// 					print_map(map, lim);
// 					writing_map(map, lim, fig, bukva, ++j);
// 				}
//             }
//         }
// 		print_map(map, lim);
// 		return (0);
// }

void	print_map(char **a, int r)
{
	size_t i;
	
	i = 0;
	while (i < r)
	{
		if (i == 0)
			write(1, "\n", 1);
		write(1, a[i], 10);
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
            a[i][j++] = '.';
        i++;
        j = 0;
    }
	print_map(a, r);
}

int		param(char **figure, int f_i)
{
		int counter;
		char symbol;

		symbol = 'A' + f_i;
		counter = 0;
		while (figure[f_i][counter] != '\n')
			counter++;
		return (counter);
}

int		write_fig(char **map, char **figure, int f_i, int lim, int sdvig)
{
		int j;
		int f;
		int	m_i;
		int len_cock;
		char *temp_look_1;

		len_cock = ft_strlen(figure[f_i]);
		m_i = 0;
		j = 0;
		f = 0;
		while (len_cock >= f && m_i < /*10*/lim  && (j < lim || figure[f_i][f] == '\n'))
		{
			if (figure[f_i][f] == '.'  && map[m_i + sdvig][j] != '.')
			{
				j++;
				f++;
			}
   			while (map[m_i + sdvig][j] != '.' && j < lim)
				j++;
			if (figure[f_i][f] == '\n')
			{
				f++;
				m_i++;
				j = j - param(figure, f_i);
			}
			if (figure[f_i][f] != '\0' && map[m_i + sdvig][j] == '.' && j < lim)
			{
				map[m_i + sdvig][j] = figure[f_i][f];
				temp_look_1 = map[m_i + sdvig];
				f++;
			}
			if (j == lim && figure[f_i][f] != '\n')
			{
				j = 0;
				m_i++;
			}
			j++;
		}
		if (f == len_cock)//
			return (1);
		if (m_i == lim && j == lim && f < len_cock)
			return (0);
		if (j <= lim && figure[f_i][f] != '\n')//
			return (-1);//
	
	return (-2);	
}

int		writing_map(char **map, int lim, char **fig, int i, int sdvig)//i eto nomer bukvy; int sdvig = po mape y po ebalu
{
	int 	m_i;
	int 	m_j;
	int 	f_i;
	int 	f_j;
	int 	check;

	m_i = 0;
    m_j = 0;
    f_i = 0;
    f_j = 0;
	if (m_i + i < lim)
	{
		check = write_fig(map, fig, i, lim, sdvig);
		print_map(map, lim);
		i++;
		if (!fig[i])
			return (1);
		if (check == 1)
			writing_map(map, lim, fig, i, 0);
		else if(check == -1)
		{
			i--;
			del_last(map, lim, i);
			print_map(map, lim);
			writing_map(map, lim, fig, i, ++sdvig);
		}
		else if (check == 0)
		{
			del_all(map, lim);
			print_map(map, lim);
			writing_map(map, ++lim, fig, 0, sdvig);
		}
	}
	print_map(map, lim);
	return (1);
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
	f[1] = "BBBB\n";
	f[2] = "CC\nCC\n";
	//f[3] = "DD\nDD\n";
	//f[4] = "I\nI\nI\nI\n";
	r = 3;
	i = 0;
	print_map(a, r);
	writing_map(a, r, f, 0, 0);
	return (4);
}