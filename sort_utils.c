/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:54:49 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/21 15:49:33 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->array[i] > a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	no_sort(void)
{
	//ft_putstr("Already sorted or no elements to sort\n");
	return (0);
}

int	find_max_index(t_stack *a)
{
	int	max_index;
	int	i;

	i = 0;
	max_index = 0;
	while (i < a->size)
	{
		if (a->array[i] > a->array[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	find_min_index(t_stack *a)
{
	int	min_index;
	int	i;

	i = 0;
	min_index = 0;
	while (i < a->size)
	{
		if (a->array[i] < a->array[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}
