/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:23:41 by smarty            #+#    #+#             */
/*   Updated: 2023/07/17 12:18:14 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (('A' <= str[i]) && (str[i] <= 'Z'))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	ft_strlowcase(str);
	i = 0;
	str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		j = i + 1;
		if ((str[i] <= 'z' && str[i] >= 'a')
			|| (str[i] <= 'Z' && str[i] >= 'A')
			|| (str[i] <= '9' && str[i] >= '0'))
			i++;
		else if (str[j] <= 'z' && str[j] >= 'a')
		{
			i++;
			str[i] = str[i] - 32;
		}
		else
			i++;
	}
	return (str);
}
