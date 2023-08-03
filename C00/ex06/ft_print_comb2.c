/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:45:36 by smarty            #+#    #+#             */
/*   Updated: 2023/07/15 18:04:15 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putchars(int c, int d)
{
	ft_putchar(c / 10 + '0');
	ft_putchar(c % 10 + '0');
	ft_putchar(' ');
	ft_putchar(d / 10 + '0');
	ft_putchar(d % 10 + '0');
	if (c < 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	c;
	int	d;

	c = 0;
	while (c <= 98)
	{
		d = c + 1;
		while (d <= 99)
		{
			ft_putchars(c, d);
			d++;
		}
		c++;
	}
}

/*int	main(void)
{
	ft_print_comb2();
}*/
