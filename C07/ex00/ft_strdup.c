/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:57:40 by smarty            #+#    #+#             */
/*   Updated: 2023/08/01 13:04:31 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		j;
	char	*dest;

	j = 0;
	dest = malloc(ft_strlen(src) * sizeof(char));
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*yo;
	
	yo = ft_strdup("bonjour");
	printf("%s",yo);
	free(yo);
}*/
