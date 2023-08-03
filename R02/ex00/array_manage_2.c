/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_manage_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:35:46 by arpages           #+#    #+#             */
/*   Updated: 2023/07/30 21:31:15 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rmemptys_2(char buffer[], int i);

void	ft_rmempty(char buffer[])
{
	int	b;
	int	i;

	b = 0;
	i = 0;
	while (*buffer)
	{
		if (*buffer >= 'a' && *buffer <= 'z')
			b = 0;
		else if (*buffer == '\n' && b < 1)
			b = 1;
		else if (*buffer == '\n' && b >= 1)
			*buffer = ' ';
		buffer++;
	}
	ft_rmemptys_2(buffer, i);
}

void	ft_rmemptys_2(char buffer[], int i)
{
	while (!(buffer[i] >= 'a' && buffer[i] <= 'z'))
	{
		if (buffer[i] == '\n')
			buffer[i] = ' ';
		i++;
	}
	while (i > 0)
	{
		if (buffer[i] == '\n')
			buffer[i] = ' ';
		i--;
	}
}
