/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:22:58 by smarty            #+#    #+#             */
/*   Updated: 2023/07/23 13:49:20 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	error(int tab[6][6])
{
	int	i;
	int	j;

	i = 1;
	while (i <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			if(tab[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	error_two_row(int tab[6][6])
{
	int	i;
	int	j;
	int	g;

	i = 1;
	while (i <= 4)
	{
		j = 1;
		while (j <= 3)
		{
		 	g = j + 1;
			while (g <= 4)
			{
				if (tab[i][j] == tab[i][g])
					return (0);
				g++;
			}
			j++;
		}
		i++;

	}
	return (1);
}

int	error_two_col(int tab[6][6])
{
	int	i;
	int	j;
	int	g;

	j = 1;
	while (j <= 4)
	{
		i = 1;
		while (i <= 3)
		{
		 	g = i + 1;
			while (g <= 4)
			{
				if (tab[i][j] == tab[g][j])
					return (0);
				g++;
			}
			i++;
		}
		j++;

	}
	return (1);
}


int	verif(int tab[6][6])
{
	if (error == 0 || error_two_row == 0 || error_two_col == 0)
		return (0);
	return (1);
}
