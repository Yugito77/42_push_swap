/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:38:17 by hcherpre          #+#    #+#             */
/*   Updated: 2022/01/13 19:43:45 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list(int argc, int c, char **av)
{
	int	i;

	if (!check_doublon(c, av) || !check_int(c, av, 0))
		return (0);
	i = c;
	while (i < argc)
	{
		if (ft_atol(av[i]) > ft_atol(av[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	check_int(int c, char **av, int j)
{
	int	i;

	i = c;
	while (av[i])
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
		{
			if (j == 1)
				return (0);
			else
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_doublon(int c, char **av)
{
	int	i;
	int	j;

	if ((c == 0 && av[1] == NULL) || (c == 1 && av[2] == NULL))
		return (0);
	i = c;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[j]) == ft_atol(av[i]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	is_digit(int c, char **av)
{
	int	i;
	int	j;

	i = c;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= 0 && av[i][j] < 32) ||
				(av[i][j] >= 33 && av[i][j] < 45) ||
				(av[i][j] >= 46 && av[i][j] <= 47) ||
				(av[i][j] >= 58 && av[i][j] < 127))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_space(char **argv)
{
	int	i;

	i = 0;
	if (!argv[1][0])
		return (1);
	while (argv[1][i])
	{
		if (argv[1][i] != 32)
			return (1);
		i++;
	}
	return (0);
}
