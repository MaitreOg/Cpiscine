/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:20:49 by smarty            #+#    #+#             */
/*   Updated: 2023/08/03 16:39:18 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_absolute(int start, int end)
{
	int	i;

	if (start > end)
		i = start - end;
	else
		i = end - start;
	return (i);
}

#include <stdlib.h>
int	*ft_rrange(int start, int end)
{
	int	i;
	int	len;
	int	*tab;
	
	i = 0;
	len = ft_absolute(start, end);
	tab = malloc(sizeof(int) * len + 1);
	if (!tab)
		return (NULL);
	if (start >= end)
	{
		while (i <= len)
		{
			tab[i] = end;
			end++;
			i++;
		}
	}
	else if (start < end)
	{
		while (i <= len)
		{
			tab[i] = end;
			end--;
			i++;
		}
	}
	return (tab);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **ag)
{
	if (ac == 3)
	{
		int	len;
		int	i;
		int	*tab;

		tab = ft_rrange(atoi(ag[1]), atoi(ag[2]));
		i = 0;
		len = ft_absolute(atoi(ag[1]), atoi(ag[2]));
		while (i <= len)
		{
			printf("%d\n", tab[i]);
			i++;
		}
		free(tab);
		return (0);
	}
	else
		return (1);
}
