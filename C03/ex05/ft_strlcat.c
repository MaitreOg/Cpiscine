/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:55:45 by smarty            #+#    #+#             */
/*   Updated: 2023/07/24 14:42:50 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	total;
	unsigned int	destlen;
	unsigned int	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	total = destlen + srclen;
	j = destlen;
	if (size <= destlen)
		return (srclen + size);
	while (src[i] && j < size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[total] = '\0';
	return (total);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int main()
{
    char            my_dest1[25] = "Bonjour";
    char            my_src1[] = " tout le monde";
    unsigned int    my_result1;

    char            origin_dest1[25] = "Bonjour";
    char            origin_src1[] = " tout le monde";
    unsigned int    origin_result1;

    char            my_dest2[25] = "Bonjour";
    char            my_src2[] = "";
    unsigned int    my_result2;

    char            origin_dest2[25] = "Bonjour";
    char            origin_src2[] = "";
    unsigned int    origin_result2;

    char            my_dest3[25] = "B";
    char            my_src3[] = "onjour  ";
    unsigned int    my_result3;

    char            origin_dest3[25] = "B";
    char            origin_src3[] = "onjour  ";
    unsigned int    origin_result3;

    my_result1 = ft_strlcat(my_dest1, my_src1, 25);
    origin_result1 = strlcat(origin_dest1, origin_src1, 25);
    printf("Mine   : %s = %u\n", my_dest1, my_result1);
    printf("Origin : %s = %u\n", origin_dest1, origin_result1);

    printf("---------\n");

    my_result2 = ft_strlcat(my_dest2, my_src2, 15);
    origin_result2 = strlcat(origin_dest2, origin_src2, 15);
    printf("Mine   : %s = %u\n", my_dest2, my_result2);
    printf("Origin : %s = %u\n", origin_dest2, origin_result2);

    printf("---------\n");

    my_result3 = ft_strlcat(my_dest3, my_src3, 6);
    origin_result3 = strlcat(origin_dest3, origin_src3, 6);
    printf("Mine   : %s = %u\n", my_dest3, my_result3);
    printf("Origin : %s = %u\n", origin_dest3, origin_result3);
    return (0);
}*/
