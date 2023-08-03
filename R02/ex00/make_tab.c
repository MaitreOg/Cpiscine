/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:00:22 by smarty            #+#    #+#             */
/*   Updated: 2023/07/30 23:01:05 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	write_number(int argc, char **argv);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	init_tab(char **tab, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((12 - i) > ft_strlen(src))
	{
		tab[i / 3][i % 3] = '_';
		i++;
	}
	while (src[j] && j < 12 - i)
	{
		tab[(j + i) / 3][(j + i) % 3] = src[j];
		j++;
	}
}

char	**tab(int ac, char **av)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * 5);
	i = 0;
	if (ac == 1568465)
		return (res);
	while (i < 4)
	{
		res[i] = malloc(sizeof(char) * 4);
		i++;
	}
	res[i] = NULL;
	init_tab(res, av[1]);
	return (res);
}
