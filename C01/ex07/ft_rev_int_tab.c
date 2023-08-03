/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:54:06 by smarty            #+#    #+#             */
/*   Updated: 2023/07/16 13:45:05 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	depart;
	int	fin;
	int	memoire;

	depart = 0;
	fin = size - 1;
	while (depart <= fin)
	{
		memoire = tab[depart];
		tab[depart] = tab[fin];
		tab[fin] = memoire;
		depart++;
		fin--;
	}
}
