/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:54:49 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/22 12:39:30 by skuznets         ###   ########.fr       */
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

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quicksort(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	if (low < high)
	{
		pivot = arr[high];
		i = low - 1;
		j = low;
		while (j < high)
		{
			if (arr[j] < pivot)
			{
				i++;
				swap(&arr[i], &arr[j]);
			}
			j++;
		}
		i++;
		swap(&arr[i], &arr[high]);
		quicksort(arr, low, i - 1);
		quicksort(arr, i + 1, high);
	}
}
