/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:03:32 by hcherpre          #+#    #+#             */
/*   Updated: 2022/01/13 19:54:14 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo(t_list **liste_a)
{
	t_list	*liste_b;

	liste_b = NULL;
	if (ft_lstsize(*liste_a) == 2)
		op_sa(liste_a);
	else if (ft_lstsize(*liste_a) == 3)
		ft_three_sorted((*liste_a)->content, (*liste_a)->next->content,
			(*liste_a)->next->next->content, liste_a);
	else if (ft_lstsize(*liste_a) == 4)
		ft_four_sorted(liste_a, &liste_b);
	else if (ft_lstsize(*liste_a) == 5)
		ft_five_sorted(liste_a, &liste_b);
	else if (ft_lstsize(*liste_a) > 5)
		ft_radix(liste_a, &liste_b, ft_lstsize(*liste_a));
}

void	create_list(int argc, int c, char **av)
{
	int		i;
	t_list	*liste_a;
	t_list	*first;

	liste_a = malloc(sizeof(t_list));
	first = malloc(sizeof(t_list));
	if (!liste_a || !first)
		return ;
	liste_a->content = ft_atol(av[c]);
	liste_a->index = 0;
	liste_a->next = NULL;
	first->next = liste_a;
	if (c == 0)
		i = 0;
	else
		i = 1;
	while (++i < argc)
		ft_lstadd_back(&first, ft_lstnew(ft_atol(av[i]), 0));
	ft_index(first, liste_a);
	liste_a = first->next;
	ft_algo(&liste_a);
	ft_lstclear(&liste_a);
	ft_lstdelone(first);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!check_int(1, argv, 1) || (argv[1][0] == ' ' && argv[1][1] == '\0') ||
		!check_space(argv))
	{
		write(2, "Error\n", 7);
		return (0);
	}
	if (!is_digit(1, argv) || argv[1][0] == '\0')
		return (0);
	main2(argc, argv);
	return (0);
}

int	main2(int argc, char **argv)
{
	char	**av;
	int		len;

	if (argc == 2)
	{
		av = ft_split(argv[1], 32);
		len = ft_strlen_tab(av);
		if (!check_list(len - 1, 0, av) || !is_digit(0, av))
		{
			ft_free(av, len);
			return (0);
		}
		create_list(len, 0, av);
		ft_free(av, len);
	}
	else if (argc > 2)
	{
		av = argv;
		if (!check_list((argc - 1), 1, av) || !is_digit(1, av))
			return (0);
		create_list(argc, 1, av);
	}
	return (0);
}
