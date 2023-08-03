/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:46:41 by smarty            #+#    #+#             */
/*   Updated: 2023/07/21 02:06:04 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	fin;
	int	memoire;
	int	depart;

	depart = 0;
	while (depart < size - 1)
	{
		fin = 0;
		while (fin < size - 1 - depart)
		{
			if (tab[fin] > tab[fin + 1])
			{
				memoire = tab[fin];
				tab[fin] = tab[fin + 1];
				tab[fin + 1] = memoire;
			}
			fin++;
		}
		depart++;
	}
}
