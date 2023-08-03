/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:24:05 by smarty            #+#    #+#             */
/*   Updated: 2023/07/26 18:24:16 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	doublechar(char *baseb)
{
	int	a;
	int	b;

	a = 0;
	while (baseb[a] != '\0')
	{
		b = a + 1;
		while (baseb[b] != '\0')
		{
			if (baseb[a] == baseb[b])
				return (1);
			++b;
		}
		a++;
	}
	return (0);
}

void	printnbr(int n, int sizeb, char *baseb)
{
	long	ofn;

	ofn = n;
	if (ofn < 0)
	{
		ft_putchar('-');
		ofn = -ofn;
	}
	if (ofn >= sizeb)
		printnbr(ofn / sizeb, sizeb, baseb);
	ft_putchar(baseb[ofn % sizeb]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	sizeb;

	sizeb = 0;
	while (base[sizeb] != '\0')
	{
		if (base[sizeb] == '+' || base[sizeb] == '-' 
			|| (base[sizeb] >= 9 && base[sizeb] <= 13)
			|| base[sizeb] == 32)
			return ;
		sizeb++;
	}
	if (sizeb <= 1)
		return ;
	if (doublechar(base))
		return ;
	printnbr(nbr, sizeb, base);
}
