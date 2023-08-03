/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:49:47 by smarty            #+#    #+#             */
/*   Updated: 2023/07/22 18:07:51 by fde-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	j;
	int	i;
	int	k;
	int	space;
	int	tab[6][6];

	space = 0;
	k = 0;
	i = 0;
	j = 1;
	if (argc != 2)
	{
		write(2, "please enter all arguments in quotation", 39);
		return (0);
	}
	while (argv[1][k])
	{
		if (argv[1][k] == ' ')
			space++;
		k++;
	}
	if (space != 15)
		write(2, "please enter the correct number of arguments", 44);
	k = 0;
	while (argv[1][k])
	{
		while (j<= 4)
		{
			tab[i][j] = argv[1][k];
			j++;
			k = k + 2;
			if (j == 4 && i  == 0)
			{
				i = 5;
				j = 1;
			}
		}
		j = 0;
		i = 1;
		while (i <= 4)
		{
			tab[i][j] = argv[1][k];
			i++;
			k = k + 2;
			if (i == 4 && j == 0)
			{
				j = 5;
				i = 1;
			}
		}
	}		
}
