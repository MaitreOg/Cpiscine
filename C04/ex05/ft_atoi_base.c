/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:49:37 by smarty            #+#    #+#             */
/*   Updated: 2023/07/26 18:19:10 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	notegal(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i++])
	{
		if (base[i] == 32 || (base[i] >= 9 && base[i] <= 13))
			return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j++])
		{
			if (base[i] == base[j])
				return (0);
		}
		j = i + 1;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	lenbase(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	get_index_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

int	test_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int		signe;
	int		i;
	int		len;
	long	result;

	len = lenbase(base);
	result = 0;
	i = 0;
	signe = 1;
	if (notegal(base) == 0)
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (test_base(str[i], base) && str[i])
	{
		result = result * len + get_index_base(str[i], base);
		i++;
	}
	return (result * signe);
}
