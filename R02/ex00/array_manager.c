/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:14:44 by arpages           #+#    #+#             */
/*   Updated: 2023/07/30 23:13:46 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "array_manager.h"

void	ft_rmempty(char buffer[]);
void	ft_putstr(char *str);

ssize_t	ft_filelenght(char buffer[])
{
	ssize_t		i;

	i = 0;
	while (*buffer)
	{
		if (*buffer == '\n')
			i++;
		buffer++;
	}
	return (i);
}

void	ift_rmempty(char buffer[])
{
	int	b;

	b = 0;
	while (*buffer)
	{
		if (*buffer == '\n' && b >= 1)
			*buffer = ' ';
		if (*buffer == '\n')
			b++;
		if (*buffer >= 'a' && *buffer <= 'z')
			b = 0;
		buffer++;
	}
}

char	**ft_assigndict(char *dict[], char buffer[])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (buffer[i])
	{
		if (buffer[i] >= 'a' && buffer[i] <= 'z')
		{
			dict[j][k] = buffer[i];
			k++;
		}
		if (buffer[i] == '\n')
		{
			k = 0;
			j++;
		}
		i++;
	}
	return (dict);
}

char	**ft_createdict(int size)
{
	int		i;
	char	**dict;

	dict = malloc(sizeof(char *) * 256);
	i = 0;
	while (i < size)
	{
		dict[i] = malloc(sizeof(char *) * 256);
		i++;
	}
	return (dict);
}

char	**ft_getdict(const char *pathname)
{
	int		fd;
	int		rslt;
	char	buffer[1024];
	char	**dict;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Dict Error\n");
		return (NULL);
	}
	rslt = read(fd, buffer, 1024);
	if (rslt == -1)
	{
		return (NULL);
		close(fd);
	}
	buffer[rslt] = '\0';
	dict = ft_createdict(rslt);
	ft_assigndict(dict, buffer);
	return (dict);
}
