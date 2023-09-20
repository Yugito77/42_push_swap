/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:37:08 by hcherpre          #+#    #+#             */
/*   Updated: 2022/01/13 19:46:27 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_list **liste_a)
{
	t_list	*tmp;

	tmp = *liste_a;
	*liste_a = (*liste_a)->next;
	ft_lstadd_back(liste_a, tmp);
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	op_rra(t_list **liste_a)
{
	t_list	*tmp;

	tmp = ft_second_last(*liste_a);
	ft_lstlast(*liste_a)->next = *liste_a;
	*liste_a = tmp->next;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	op_pb(t_list **liste_a, t_list **liste_b)
{
	t_list	*save;

	save = *liste_a;
	ft_lstadd_front(liste_b, ft_lstnew((*liste_a)->content, (*liste_a)->index));
	*liste_a = (*liste_a)->next;
	ft_lstdelone(save);
	write(1, "pb\n", 3);
}

void	op_pa(t_list **liste_a, t_list **liste_b)
{
	t_list	*save;

	save = *liste_b;
	ft_lstadd_front(liste_a, ft_lstnew((*liste_b)->content, (*liste_b)->index));
	*liste_b = (*liste_b)->next;
	ft_lstdelone(save);
	write(1, "pa\n", 3);
}

void	op_sa(t_list **liste_a)
{
	t_list	*temp;

	temp = *liste_a;
	*liste_a = (*liste_a)->next;
	temp->next = (*liste_a)->next;
	(*liste_a)->next = temp;
	write(1, "sa\n", 3);
}
