/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:33:49 by nsalles           #+#    #+#             */
/*   Updated: 2023/07/31 19:20:52 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int	algo(char **map);
char	**get_tab_map(char *filename, int size_x, int size_y);

int	main(int argc, char **argv)
{
	int	size_x;
	int	size_y;
	int	i;
	char	**tab;	

	i = 0;
	tab = get_tab_map("map", 20, 20);
	while (i < 20)
	{
		printf("%s\n", tab[i++]);
	}
	algo(get_tab_map("map", 20, 20));
	return (0);
}
