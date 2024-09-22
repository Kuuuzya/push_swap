/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:07:53 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/22 12:09:08 by skuznets         ###   ########.fr       */
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
