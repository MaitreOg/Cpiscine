/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:27:20 by smarty            #+#    #+#             */
/*   Updated: 2023/07/17 19:44:31 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	fin;

	i = 0;
	fin = 0;
	while (dest[fin] != '\0')
	{
		fin++;
	}
	while (src[i] != '\0' && i < nb)
	{
		dest[fin] = src[i];
		fin++;
		i++;
	}
	dest[fin] = '\0';
	return (dest);
}
