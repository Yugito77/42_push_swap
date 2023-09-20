/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:55:57 by hcherpre          #+#    #+#             */
/*   Updated: 2022/01/13 19:44:54 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bit(int size)
{
	int	i;

	i = 0;
	while ((size >> i) != 0)
		i++;
	return (i);
}

void	ft_radix(t_list **liste_a, t_list **liste_b, int size)
{
	int	i;
	int	j;
	int	c;
	int	max;

	i = 0;
	max = max_bit(size);
	while (i < max)
	{
		j = 0;
		c = 0;
		while (j++ < size)
		{
			if (((((*liste_a)->index) >> i) & 1) == 1)
				op_ra(liste_a);
			else
			{
				op_pb(liste_a, liste_b);
				c++;
			}
		}
		while (c-- != 0)
			op_pa(liste_a, liste_b);
		i++;
	}
}
