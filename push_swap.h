/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:46:18 by hcherpre          #+#    #+#             */
/*   Updated: 2022/01/13 19:44:46 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/********************* CREATE STRUCTURE **************************************/

typedef struct Liste
{
	int				content;
	int				index;
	struct Liste	*next;
}					t_list;

/***************************  LISTE ******************************************/

t_list		*ft_lstnew(int content, int index);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_second_last(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		create_list(int argc, int c, char **av);
void		ft_lstclear(t_list **lst);
void		ft_lstdelone(t_list *lst);
int			ft_lstsize(t_list *lst);

/************************** CHECK LISTE **************************************/

int			main2(int argc, char **argv);
int			check_list(int argc, int c, char **av);
int			check_int(int c, char **av, int j);
int			is_digit(int c, char **av);
int			check_doublon(int c, char**av);
int			check_space(char **argv);

/***************************** LIBFT *****************************************/

size_t		ft_strlen(char	*c);
size_t		ft_strlen_tab(char **tab);
long int	ft_atol(const char *str);
char		**ft_split(char const *s1, char c);

/*************************** OPERATIONS **************************************/

void		op_sa(t_list **liste_a);
void		op_ra(t_list **liste_a);
void		op_rra(t_list **liste_a);
void		op_pb(t_list **liste_a, t_list **liste_b);
void		op_pa(t_list **liste_a, t_list **liste_b);

/*************************** ALGORITHME **************************************/

void		ft_algo(t_list **liste_a);
void		ft_three_sorted(int cont1, int cont2, int cont3, t_list **liste_a);
void		ft_four_sorted(t_list **liste_a, t_list **liste_b);
void		ft_five_sorted(t_list **liste_a, t_list **liste_b);
void		ft_five_2_sorted(t_list **liste_a, t_list **liste_b);
void		ft_radix(t_list **liste_a, t_list **liste_b, int size);

/************************ BITS AND INDEX **************************************/

int			max_bit(int size);
void		ft_index(t_list *first, t_list *liste_a);

/*************************** FREE *********************************************/

void		ft_free(char **av, int len);

#endif
