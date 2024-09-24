/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:07:53 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/24 14:19:31 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	has_duplicates(int argc, char **argv)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i], &num_i) != 0)
			return (1);
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[j], &num_j) != 0)
				return (1);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check(int argc, char *argv[])
{
	int		i;
	long	value;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (ft_atoi(argv[i], &value) != 0)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	if (has_duplicates(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

void	free_args(char **args, int count)
{
	int	i;

	i = 1;
	while (i < count)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_all(t_stack *a, t_stack *b, char **args, int count)
{
	free_stack(a);
	free_stack(b);
	free_args(args, count);
}
