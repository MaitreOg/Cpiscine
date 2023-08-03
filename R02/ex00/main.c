/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:31:45 by svidot            #+#    #+#             */
/*   Updated: 2023/07/30 23:14:07 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "array_manager.h"
#include <unistd.h>

char	**tab(int argc, char **argv);
char	**ft_getdict(const char *pathname);
void	aff(char **tabl, char **dict);
char	**ft_create_tab(int argc, char **argv);

int	main(int argc, char **argv)
{
	char		**dict;
	char		**tabl;
	const char	*pathname;

	tabl = tab(argc, argv);
	pathname = "numbers.dict";
	dict = ft_getdict(pathname);
	aff(tabl, dict);
	free(tabl[0]);
	free(tabl[1]);
	free(tabl[2]);
	free(tabl[3]);
	free(tabl[4]);
	free(tabl);
	return (0);
}
