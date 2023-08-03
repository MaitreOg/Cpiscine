/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:34:20 by smarty            #+#    #+#             */
/*   Updated: 2023/07/30 22:58:13 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	**tab(int argc, char **argv);
char	**ft_getdict(const char *pathname);
int		check_zero(char **tabl, char **dict);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write (1, " ", 1);
}

void	aff_2(char **tabl, char **dict, int i)
{
	int	c;

	if (tabl[i][0] > '0' && tabl[i][0] <= '9')
	{
		c = tabl[i][0] - '0';
		ft_putstr(dict[c]);
		ft_putstr(dict[28]);
	}
	else if (tabl[i][1] > '1' && tabl[i][1] <= '9')
	{
		c = tabl[i][1] - '0' + 18;
		ft_putstr(dict[c]);
	}
	if (tabl[i][2] > '0' && tabl[i][2] <= '9' && tabl[i][1] != '1')
	{
		c = tabl[i][2] - '0';
		ft_putstr(dict[c]);
	}
	if (tabl[i][1] == '1')
	{
		c = tabl[i][2] - '0' + 10;
		ft_putstr(dict[c]);
	}
}

void	aff(char **tabl, char **dict)
{
	int	i;
	int	zero;

	i = 0;
	zero = check_zero(tabl, dict);
	if (zero == 0)
		i = 5;
	while (i < 4)
	{
		if (tabl[i][0] == '0' && tabl[i][1] == '0' && tabl[i][2] == '0')
			i++;
		else
		{
			aff_2(tabl, dict, i);
			if (i == 0 && tabl[i][2] != '_')
				ft_putstr(dict[31]);
			if (i == 1 && tabl[i][2] != '_') 
				ft_putstr(dict[30]);
			if (i == 2 && tabl[i][2] != '_') 
				ft_putstr(dict[29]);
			i++;
		}
	}
}

int	check_zero(char **tabl, char **dict)
{
	if (tabl[0][0] == '_' && tabl[0][1] == '_' && tabl[0][2] == '_')
	{
		if (tabl[1][0] == '_' && tabl[1][1] == '_' && tabl[1][2] == '_')
		{
			if (tabl[2][0] == '_' && tabl[2][1] == '_' && \
					tabl[2][2] == '_')
			{
				if (tabl[3][0] == '_' && tabl[3][1] == '_' && \
					tabl[3][2] == '0')
					ft_putstr(dict[0]);
				return (0);
			}
			return (2);
		}
	}
	return (1);
}
