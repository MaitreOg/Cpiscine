/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:33:04 by smarty            #+#    #+#             */
/*   Updated: 2023/07/20 18:42:16 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nbr)
{
	if (nbr == 0 || nbr == 1)
		return (1);
	if (nbr < 0)
		return (0);
	return (nbr * ft_recursive_factorial(nbr - 1));
}
