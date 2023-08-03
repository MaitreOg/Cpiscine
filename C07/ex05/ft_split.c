/* ***********k++*************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:03:55 by smarty            #+#    #+#             */
/*   Updated: 2023/08/02 23:39:55 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_word(char *str, char *charset)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == str[i] && charset[j] != str[i - 1])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	get_char(int i, char *str, char *charset)
{
	int	j;

	j = 0;
	while (charset[j])
	{
		if (charset[j] == str[i])
			return (1);
		j++;
	}
	return (0);
}

char	**complet_tab(char *str,char *charset, char **tab)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (str[k])
	{

		while (get_char(k, str, charset) == 0)
		{
			tab[j][i] = str[k];
			i++;
			k++;
		}
		tab[j][0] = '\0';
		if (get_char(k, str, charset) == 1 && \
				get_char(k - 1, str, charset) != 1)
		{
			k++;
			j++;
			i = 0;
		}
		else
			k++;
	}
	tab[j] = NULL;
	return(tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int	len_word;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * count_word(str, charset) + 1);
	while (str[i])
	{
		len_word = 0;
		while (get_char(i, str, charset) == 0)
		{
			len_word++;
			i++;
		}
		tab[j] = malloc(sizeof(char) * len_word + 1);
		while (get_char(i, str, charset) == 1)
			i++;
			
		j++;
	}
	tab[j] = malloc(sizeof(char) * 1);
	complet_tab(str, charset, tab);
	return(tab);
}
/*
#include <stdio.h>

int		main(void)
{
	char **tab;
	i = count_word("salut sssssssssssa sert a srien", "s");
	printf("%d", i);
	tab = ft_split("Ceci&est$un##############################################################################################################################################################succes@!", "&$#@");
	printf("%s\n", ft_split(tab, "&$#@ "));
	tab = ft_split("Success", "CUT");
	printf("%s\n", ft_split(tab, " "));
	tab = ft_split("Success", "");
	printf("%s\n", ft_split(tab, " "));
	tab = ft_split("", "");
	printf("OK\n");
	tab = ft_split("", "CUT");
	printf("OK\n");
	tab = ft_split("       ", "       ");
	printf("OK\n");
	tab = ft_split("         ", "       ");
	printf("OK\n");*/
}
