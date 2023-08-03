/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:07:48 by smarty            #+#    #+#             */
/*   Updated: 2023/08/01 01:36:51 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

char	find_min(int **map, int x, int y)
{
	int	memoire;

	memoire = map[y][x - 1];
	if(memoire > map[y - 1][x - 1])
	       memoire = map[y - 1][x - 1];
	if(memoire > map[y - 1][x])	
		memoire = map[y - 1][x];
	if (map[y][x] > memoire)
		map[y][x] = (memoire + 1);
	return (map[y][x]);
}
int	**make_map(char **map)
{
	int	x;
	int	y;
	int	i;
	int	**tab;
	
	i = 0;
	x = 0;
	y = 0;
	while (map[y][x] != '\0')
		x++;
	while (map[y] != NULL)
		y++;
	tab = malloc(sizeof(int *) * y);
	while (i < y) 
	{
		tab[y] = malloc(sizeof(char) * x);
		i++;
	}
	return (tab);

}
int	**map_convert(char **map)
{
	int	**tab;
	int	x;
	int	y;

	x = 0;
	y = 0;
	tab = make_map(map);
/*	while (y < 20)                //seg fault
	{
		if (map[y][x] == '.')
			tab[y][x] = 1;
		else if (map[y][x] == 'o')
			tab[y][x] = 0;
		else if (map[y][x])
		{
			y++;
			x = -1;
		}
		x++;
	}*/
	return (tab);
}	
	 
int	algo(char **maps)
{
	int	x;
	int	y;
	int	finalx;
	int	finaly;
	int	final_result;
	int	**map;

	map = map_convert(maps);
	y = 1;
	x = 1;
	while (++y < 20)
	{
		if (map[x][y] > 0)
		{	
			map[x][y] = find_min(map,x,y);
			x++;
		}
		else if (map[x][y] == 0)
			x++;
		if (map[x][y] > final_result)
		{
			final_result = map[x][y];
			finalx = x;
			finaly = y;
		}
		else if  (!(map[x][y] >= 0 && map[x][y] <= 9))
		{
			x++;
			y = 1;
		}

	}
	x = 0;
	printf("\n\n");
	printf("coord -> x: %d, y: %d.\n valeur :%d ", finalx, finaly, final_result);
        printf("\n\n");
        map = map_convert(maps);
 /*       while (x < 20)
        {
                printf("%s\n", map[x++]);
        }*/
	return (0);

}
