/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 01:28:23 by smarty            #+#    #+#             */
/*   Updated: 2023/08/01 15:52:57 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	**ft_putstrs(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc >= 1)
	{
		while (i < argc)
		{
			ft_putstr(argv[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0' )
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		dif;
	char	*memoire;

	i = 1;
	j = 1;
	while (1 < argc - i)
	{
		j = 0;
		while (j < argc - i)
		{
			dif = ft_strcmp(argv[j], argv[j + 1]);
			if (dif > 0)
			{
				memoire = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = memoire;
			}
			j++;
		}
		i++;
	}
	ft_putstrs(argc, argv);
}
