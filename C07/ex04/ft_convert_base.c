/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:58:34 by smarty            #+#    #+#             */
/*   Updated: 2023/08/01 21:14:29 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	error(char *base)
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

int	lenbasea(char *base)
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

	len = lenbasea(base);
	result = 0;
	i = 0;
	signe = 1;
	if (error(base) == 0)
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

