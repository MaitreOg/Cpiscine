/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:16:14 by smarty            #+#    #+#             */
/*   Updated: 2023/08/03 15:28:15 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	j;

	j = 0;
	if (min >= max)
		return (NULL);
	tab = malloc((max - min) * sizeof(int));
	if (tab == NULL)
		return (NULL);
	while (j < (max - min))
	{
		tab[j] = j + min;
		j++;
	}
	return (tab);
}
/*
#include <stdio.h>

int	main(void)
{
	int i = 0;
	int *tab;
	int max = 5;
	int min = -5;
	
	tab = ft_range(min, max);
	while (i < (max - min))
	{
		printf("%d", tab[i]);
		i++;
	}
}*/
