/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:10:44 by hcherpre          #+#    #+#             */
/*   Updated: 2022/01/13 19:44:58 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_sorted(int cont1, int cont2, int cont3, t_list **liste_a)
{
	if (cont1 < cont2 && cont2 > cont3 && cont1 < cont3)
	{
		op_sa(liste_a);
		op_ra(liste_a);
	}
	if (cont1 < cont2 && cont2 > cont3 && cont1 > cont3)
		op_rra(liste_a);
	if (cont1 > cont2 && cont2 < cont3 && cont1 < cont3)
		op_sa(liste_a);
	if (cont1 > cont2 && cont2 > cont3 && cont1 > cont3)
	{
		op_sa(liste_a);
		op_rra(liste_a);
	}
	if (cont1 > cont2 && cont2 < cont3 && cont1 > cont3)
		op_ra(liste_a);
}

void	ft_four_sorted(t_list **liste_a, t_list **liste_b)
{
	if ((*liste_a)->index != 0)
	{
		while ((*liste_a)->index != 0)
		{
			if ((*liste_a)->next->index == 0)
				op_sa(liste_a);
			else
				op_rra(liste_a);
		}
		op_pb(liste_a, liste_b);
		ft_three_sorted((*liste_a)->content, (*liste_a)->next->content,
			(*liste_a)->next->next->content, liste_a);
		op_pa(liste_a, liste_b);
	}
	else
	{
		op_pb(liste_a, liste_b);
		ft_three_sorted((*liste_a)->content, (*liste_a)->next->content,
			(*liste_a)->next->next->content, liste_a);
		op_pa(liste_a, liste_b);
	}
}

void	ft_five_sorted(t_list **liste_a, t_list **liste_b)
{
	int	c;

	c = 0;
	while (c < 2)
	{
		if ((*liste_a)->index != c)
		{
			while ((*liste_a)->index != c)
			{
				if ((*liste_a)->next->index == c)
					op_sa(liste_a);
				else
					op_rra(liste_a);
			}
			op_pb(liste_a, liste_b);
			c++;
		}
		else
		{
			op_pb(liste_a, liste_b);
			c++;
		}
	}
	ft_five_2_sorted(liste_a, liste_b);
}

void	ft_five_2_sorted(t_list **liste_a, t_list **liste_b)
{
	ft_three_sorted((*liste_a)->content, (*liste_a)->next->content,
		(*liste_a)->next->next->content, liste_a);
	op_pa(liste_a, liste_b);
	op_pa(liste_a, liste_b);
}
