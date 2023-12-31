/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:38:50 by smarty            #+#    #+#             */
/*   Updated: 2023/07/16 21:43:16 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((('a' <= str[i]) && (str[i] <= 'z')) || \
					(('A' <= str[i]) && (str[i] <= 'Z')))
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
