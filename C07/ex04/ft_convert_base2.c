/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:23:02 by smarty            #+#    #+#             */
/*   Updated: 2023/08/02 23:39:34 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_atoi_base(char *str, char *base);
int	lenbasea(char *base);
int	error(char *base);


void	affect_nbr(long result, int i, char *base, char *resultat)
{
	int	sizeb;

	sizeb = 0;
	while (base[sizeb])
		sizeb++;
	if (result >= sizeb)
	{
		affect_nbr(result / sizeb, i - 1, base,resultat);
		affect_nbr(result % sizeb, i, base,resultat);
	}
	else
		resultat[i] = base[result % sizeb];
}

int	len_base(long nb, char *base)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i = 1;
	}
	if (nb == 0)
		return(1);
	if (nb > 0)
	{
		nb /= lenbasea(base);
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	int	lenbase;
	char	*resultat;
	
	
	if (error(base_from) == 0)
		return (0);
	if(error(base_to) == 0)
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	lenbase = len_base(nb, base_to);
	resultat = malloc(sizeof(char) * (lenbase + 1));
	if (nb < 0)
	{
		nb *= -1;
		resultat[0] = '-';
	}
	affect_nbr(nb, lenbase - 1, base_to, resultat);
	resultat[lenbase] = '\0';
	return (resultat);
	
}
/*
#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	printf("42:%s\n", ft_convert_base("--2a", "0123456789abcdef", "0123456789"));
	printf("-2a:%s\n", ft_convert_base("-42", "0123456789", "0123456789abcdef"));
}*/
