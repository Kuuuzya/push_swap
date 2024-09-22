/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:31:57 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/22 12:39:14 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restore_original_values(t_stack *a, int *sorted_arr, int total_size)
{
	int	i;

	i = 0;
	while (i < total_size)
	{
		a->array[i] = sorted_arr[a->array[i]];
		i++;
	}
}

int	*create_sorted_array(t_stack *s)
{
	int	*arr;
	int	i;

	arr = malloc(s->size * sizeof(int));
	i = 0;
	while (i < s->size)
	{
		arr[i] = s->array[i];
		i++;
	}
	quicksort(arr, 0, s->size - 1);
	return (arr);
}

void	assign_indices(t_stack *a, int *sorted_arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->array[i] == sorted_arr[j])
			{
				a->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	find_max_position(t_stack *b)
{
	int	max_pos;
	int	max_value;
	int	i;

	max_pos = 0;
	i = 1;
	max_value = b->array[0];
	while (i < b->size)
	{
		if (b->array[i] > max_value)
		{
			max_value = b->array[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

void	rotate_b_to_top(t_stack *b, int max_pos)
{
	if (max_pos <= b->size / 2)
	{
		while (max_pos > 0)
		{
			do_rb(b);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < b->size)
		{
			do_rrb(b);
			max_pos++;
		}
	}
}
