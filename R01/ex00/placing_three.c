/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oloncle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:02:54 by oloncle           #+#    #+#             */
/*   Updated: 2023/07/23 13:05:22 by oloncle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	placing_minus_rows_up(int t, int tab[t][t], int nb[4], int j)
{
	nb[0] += tab[1][j];
	if (tab[1][j] == 0 && (tab[0][j] == 3 || (tab[1][j + 1] == 3
	&& j == (t - 2)) || (j == 1 && (tab[1][j - 1] == 3))))
	{
		nb[0] += -1;
		tab[1][j] = -1;
	}
}

void	placing_minus_rows(int t, int tab[t][t], int nb[4], int i)
{
	int	j;

	j = 0;
	while (++j < (t - 1))
	{
		if (i == 1)
			placing_minus_rows_up(t, tab, nb, j);
		else
		{
			nb[3] += tab[i][j];
			if (tab[i][j] == 0 && (tab[i + 1][j] == 3 || (tab[i][j + 1] == 3
			&& j == (t - 2)) || (j == 1 && tab[i][j - 1] == 3)))
			{
				nb[3] += -1;
				tab[i][j] = -1;
			}
		}
	}
}

void	placing_minus(int taille, int tab[taille][taille], int nb[4])
{
	int	i;

	i = 0;
	nb[0] = 0;
	nb[1] = 0;
	nb[2] = 0;
	while (++i < (taille - 1))
	{
		if (i == 1 || i == (taille - 2))
		{
			placing_minus_rows(taille, tab, nb, i);
		}
		nb[1] += tab[i][1];
		if (tab[i][0] == 3 && tab[i][1] == 0)
		{
			tab[i][1] = -1;
			nb[1] += -1;
		}
		nb[2] += tab[i][taille - 2];
		if (tab[i][taille - 1] == 3 && tab[i][taille - 2] == 0)
		{
			tab[i][taille - 2] = -1;
			nb[2] += -1;
		}
	}
}

void	replace_minus(int taille, int tab[taille][taille])
{
	int	i;
	int	j;

	i = 1;
	while (i < (taille - 1))
	{
		if (i == 1 || i == (taille - 2))
		{
			j = 1;
			while (j < (taille - 1))
			{
				if (tab[i][j] == -1)
					tab[i][j] = 0;
				if (tab[j][i] == -1)
					tab[j][i] = 0;
				j++;
			}
		}
		i++;
	}
}

void	placing_three(int taille, int tab[taille][taille])
{
	int	i;
	int	j;
	int	nb[4];

	nb[3] = 0;
	placing_minus(taille, tab, nb);
	i = 0;
	while (++i < (taille - 1))
	{
		if (i == 1 || i == (taille - 2))
		{
			j = 0;
			while (++j < (taille - 1))
			{
				if ((tab[i][j] == 0 && nb[0] == 2 && i == 1)
				|| (tab[i][j] == 0 && nb[3] == 2 && i == (taille - 2)))
					tab[i][j] = 3;
				if ((tab[j][i] == 0 && nb[1] == 2 && i == 1)
				|| (tab[j][i] == 0 && nb[2] == 2 && i == (taille - 2)))
					tab[j][i] = 3;
			}
		}
	}
	replace_minus(taille, tab);
}
