/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:30:34 by smarty            #+#    #+#             */
/*   Updated: 2023/07/15 13:33:34 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_first_r(int c)
{
	char	angle;
	char	centre;
	int	i;

	i = 1;
	angle = 'A';
	centre = 'B';
	if (i == 1 || i == c)
	{
		ft_putchar(angle);
		i++;
	}
	else
	{
		ft_putchar(centre);
		i++;
	}
}

void	ft_last_r(int c)
{
	char	angle;
	char	centre;
	int	i;

	i = 1;
	angle = 'C';
	centre = 'B';
	if (i == 1 || i == c)
	{
		ft_putchar(angle);
		i++;
	}
	else
	{
		ft_putchar(centre);
		i++;
	}
}

void	ft_body(int c)
{
	char	angle;
	char	centre;
	int	i;

	i = 1;
	angle = 'B';
	centre = ' ';
	if (i == 1, || i == c)
	{
		ft_putchar(angle);
		i++;
	}
	else
	{
		ft_putchar(centre);
		i++;
	}
}

int	test(int c, int r)
{
	if (c == 0 || r == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

void	rush(int nb_c, nb_l)
{
	int	i;
	int	test;
	
	test = test(nb_c, nb_l);
	i = 1;
	if (test == 1)
	{
		while (i <= nb_c)
		{
			if (i == 1)
			{
				ft_first_r(nb_c);
				i++;
			}
			else if (i == nb_l)
			{
				ft_last_r(nb_c);
				i++;
			}
			else
			{
				ft_body(nb_c);
				i++;
			}
		}
	}
}
