/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:54:32 by nsalles           #+#    #+#             */
/*   Updated: 2023/07/31 19:16:42 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>

char	*readmap(char *filename, int size_x, int size_y)
{
	char	*str;
	int		file;
	char	c;
	int		index;

	c = 0;
	index = 0;
	file = open(filename, 0);
	if (file < 0)
		write(2, "Error: cannot open file\n", 24);
	str = (char *)malloc(sizeof(char) * (((size_x + 1) * size_y) + 1));
	read(file, &c, 1);
	while (c != '\n')
		read(file, &c, 1);
	while (read(file, &c, 1) == 1)
		str[index++] = c;
	str[index] = '\0';
	close(file);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**get_tab_map(char *filename, int size_x, int size_y)
{
	char	*str;
	char	**tab;
	int		i;
	int		str_size;
	
	str = readmap(filename, size_x, size_y);
	tab = (char **)malloc(sizeof(char *) * size_y);
	i = -1;
	while (++i < size_y)
		tab[i] = (char *)malloc(sizeof(char) * size_x + 1);
	str_size = (size_x + 1) * size_y;
	i = -1;
	while (++i < str_size)
	{
		if (str[i] != '\n')
			tab[i / (size_x + 1)][i % (size_x + 1)] = str[i];
		else
			tab[i / (size_x + 1)][i % (size_x + 1)] = '\0';
	}
	return (tab);
}
