/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_ft_placing_three_V2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:38:05 by fde-sain          #+#    #+#             */
/*   Updated: 2023/07/23 13:53:22 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	verif(int tab[6][6]);

void put_char(char c)
{
	write(1, &c, 1);
}
void	probabilite(int taille1, int placex,int placey , int tab[taille1][taille1])
{
	int i;
	int tmp;
	int tmpnbr[4]={1,2,3,4};
	int itmp;

	itmp = 0;
	tmp = 0;
	i = 1;
	while (i < taille1-1)
	{
		if (tab[placex][i] != 0)
			while (itmp < 4)
			{
				if (tab[placex][i] == tmpnbr[itmp])
					tmpnbr[itmp] = 0;
				itmp++;
			}
		itmp = 0;
		i++;
	}
	i = 1;
	while (i < taille1-1)
        {
                if (tab[i][placey] != 0)
                        while (itmp < 4)
                        {
                                if (tab[i][placey] == tmpnbr[itmp])
                                        tmpnbr[itmp] = 0;
                                itmp++;
                        }
		itmp = 0;
                i++;
        }
	while (itmp < 4)
	{
		if (tmpnbr[itmp] != 0)
		{
			tmp++;
			i = tmpnbr[itmp];
		}
		itmp++;
	}
	if (tmp == 1)
		tab[placex][placey] = i;
}
void patern (int taille, int tab[taille][taille])
{
        int i;

        i =0;
        while (i < taille)
        {
                if (tab[0][i] == 2 && tab[1][i] == 3 && tab[2][i] == 4 && tab[taille -1][i] == 3)
                {
                        tab[3][i] = 2;
                        tab[4][i] = 1;
                }
                i++;
        }
        i = 0;
        while (i < taille)
        {
                if (tab[taille - 1][i] == 2 && tab[taille - 2][i] == 3 && tab[taille - 3][i] == 4 && tab[0][i] == 3)
                {
                        tab[taille - 4][i] = 2;
                        tab[taille - 5][i] = 1;
                }
                i++;
        }
}
void paterncol(int taille, int tab[taille][taille])
{
        int i;

        i =0;
        while (i < taille)
        {
                if (tab[i][0] == 2 && tab[i][1] == 3 && tab[i][2] == 4 && tab[i][taille-1] == 3)
                {
                        tab[i][3] = 2;
                        tab[i][4] = 1;
                }
                i++;
        }
        i = 0;
        while (i < taille)
        {
                if (tab[i][taille -1] == 2 && tab[i][taille - 2] == 3 && tab[i][taille - 3] == 4 && tab[i][0] == 3)
                {
                        tab[i][taille - 4] = 2;
                        tab[i][taille - 5] = 1;
                }
                i++;
        }
}
void	affichage(int taille1, int taille2, int tab[taille1][taille2])
{
	int i;
	int j;
	i = 1;
	j = 1;
	while (i < taille1 - 1)
	{
		while (j < taille2 - 1)
		{
			put_char(tab[i][j] + 48);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
	j=1;
	i++;
	}
}

void	placing_three(int taille1, int taille2, int tab[taille1][taille2])
{
	int	i;
	int	j;
	int	nb[4] = {0,0,0,0};

	i = 1;
	while (i < (taille1 - 1))
	{
		if (i == 1 || i == (taille1 - 2))
		{
			j = 1;
			while (j < (taille1 - 1))
			{
				if (i == 1)
				{
					if (tab[i][j] == 0 && (tab[i - 1][j] == 3 || (tab[i][j+1] == 3 && j == (taille1 - 2)) || (j == 1 && (tab[i][j-1] == 3))))
					{
						nb[0] += -1;
						tab[i][j] = -1;	
					}
					else
						nb[0] += tab[i][j];
				}
				else
				{
					if (tab[i][j] == 0 && (tab[i + 1][j] == 3 || (tab[i][j+1] == 3 && j == (taille1 -2)) || (j == 1 && tab[i][j-1] == 3)))
					{
						nb[3] += -1;
						tab[i][j] = -1;
					}	
					else
						nb[3] += tab[i][j];
				}
				j++;
			}
		}
		if (tab[i][0] == 3 && tab[i][1] == 0)
		{
			tab[i][1] = -1;
			nb[1] += -1;
		}
		else
			nb[1] += tab[i][1];
		if (tab[i][taille1 - 1] == 3 && tab[i][taille1 - 2] == 0)
		{
			tab[i][taille1 - 2] = -1;
			nb[2] += -1;
		}
		else
			nb[2] += tab[i][taille1 - 2];
		i++;
	}
	i = 1;
	while (i < (taille1 - 1))
	{
		if (i == 1 || i == (taille1 - 2))
		{
			j = 1;
			while (j < (taille1 - 1))
			{
				if (tab[i][j] == 0 && nb[0] == 2 && i == 1)
					tab[i][j] = 3;
				if (tab[j][i] == 0 && nb[1] == 2 && i == 1)
					tab[j][i] = 3;
				if (tab[j][i] == 0 && nb[2] == 2 && i == (taille1 - 2))
					tab[j][i] = 3;
				if (tab[i][j] == 0 && nb[3] == 2 && i == (taille1 - 2))
					tab[i][j] = 3;
				j++;
			}
		}
		i++;
	}
	i = 1;
	while (i < (taille1 - 1))
	{
		if (i == 1 || i == (taille1 - 2))
		{
			j = 1;
			while (j < (taille1 - 1))
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

void	calculcolup(int taille1, int taille2, int tab[taille1][taille2])
{
	int i;

	i=0;
	while(i < taille2)
	{
		if (tab[0][i] == 1)
			tab[1][i] = 4;
		if (tab[0][i] == 4)
		{
			tab[1][i] = 1;
			tab[2][i] = 2;
			tab[3][i] = 3;
		}
		if (tab[0][i] == 2 && tab[taille2 - 1][i] == 1)
			tab[1][i] = 3;
		if (tab[0][i] == 3 && tab[taille2 - 1][i] == 2)
			tab[3][i] = 4;
		i++;
	}
}
void    calculcoldown(int taille1, int taille2, int tab[taille1][taille2])
{
        int i;

        i=0;
        while(i < taille2)
        {
                if (tab[taille2-1][i] == 1)
                        tab[taille2-2][i] = 4;
                if (tab[taille2-1][i] == 4)
                {
                        tab[taille2-2][i] = 1;
                        tab[taille2-3][i] = 2;
                        tab[taille2-4][i] = 3;
                }
		if (tab[taille2-1][i] == 2 && tab[0][i] == 1)
			tab[taille2-2][i] = 3;
		if (tab[taille2-1][i] == 3 && tab[0][i] == 2)
                        tab[taille2-4][i] = 4;
                i++;
        }
}
void    calculrowleft(int taille1, int taille2, int tab[taille1][taille2])
{
        int i;

        i=0;
        while(i < taille2)
        {
                if (tab[i][0] == 1)
                        tab[i][1] = 4;
                if (tab[i][0] == 4)
                {
                        tab[i][1] = 1;
                        tab[i][2] = 2;
                        tab[i][3] = 3;
                }
		if (tab[i][0] == 2 && tab[i][taille2-1] == 1)
			tab[i][1] = 3;
		if (tab[i][0] == 3 && tab[i][taille2-1] == 2)
                        tab[i][3] = 4;
                i++;
        }
}
void    calculrowright(int taille1, int taille2, int tab[taille1][taille2])
{
        int i;

        i=0;
        while(i < taille2)
        {
                if (tab[i][taille2 - 1] == 1)
                        tab[i][taille2 - 2] = 4;
                if (tab[i][taille2 - 1] == 4)
                {
                        tab[i][taille2 -2] = 1;
                        tab[i][taille2 -3] = 2;
                        tab[i][taille2 -4] = 3;
                }
		if (tab[i][taille2 - 1] == 2 && tab[i][0] == 1)
			tab[i][taille2 - 2] = 3;
		if (tab[i][taille2 - 1] == 3 && tab[i][0] == 2)
                        tab[i][taille2 - 4] = 4;
                i++;
        }
}

int	main(int argc, char *argv[])
{
	int tab[6][6] =
	{
		{0,3,2,1,2,0},
		{4,0,0,0,0,2},
		{4,0,0,0,0,3},
		{3,0,0,0,0,1},
		{1,0,0,0,0,3},
		{0,1,2,3,2,0}
	};
	int i1;
	int i2;
	int i;

	i = 0;
	i1 = 0;
	i2 = 0;
	calculcolup(6,6,tab);
	calculcoldown(6,6,tab);
	calculrowleft(6,6,tab);
	calculrowright(6,6,tab);
	placing_three(6,6,tab);
	while (i <6)
	{
		patern(6,tab);
		paterncol(6,tab);
		while (i1 < 6)
		{
			while(i2 <6)
			{
				if (tab[i1][i2] == 0)
					probabilite(6, i1, i2, tab);
				i2++;
			}
			i2=0;
			i1++;
		}
		i1 = 0;
		i++;
	}
	if (verif(tab))
		affichage(6,6,tab);
	else
		write(1, "Error\n", 6);
}
