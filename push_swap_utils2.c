/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:33:48 by hcherpre          #+#    #+#             */
/*   Updated: 2022/01/13 19:46:15 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_list *first, t_list *liste_a)
{
	t_list	*temp;
	int		j;
	int		len;

	len = ft_lstsize(liste_a) - 1;
	temp = first->next;
	while (temp)
	{
		liste_a = first->next;
		j = 0;
		while (liste_a)
		{
			if (liste_a->content > temp->content)
			{
				j++;
				liste_a = liste_a->next;
			}
			else
				liste_a = liste_a->next;
		}
		temp->index = len - j;
		temp = temp->next;
	}
	liste_a = first->next;
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
}

void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		lst->content = 0;
		lst->index = 0;
		free(lst);
	}
}

void	ft_free(char **av, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(av[i]);
		i++;
	}
	free(av);
}
