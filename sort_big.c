/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:17:01 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/23 15:53:26 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_sort(t_stack *a, int **sorted_arr, int *chunk_size)
{
	*sorted_arr = create_sorted_array(a);
	assign_indices(a, *sorted_arr);
	if (a->size <= 100)
		*chunk_size = 15;
	else
		*chunk_size = 30;
}

void	move_chunks_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	current;

	current = 0;
	while (a->size > 0)
	{
		if (a->array[0] <= current)
		{
			do_pb(a, b);
			if (b->size > 1 && b->array[0] < b->array[1])
				do_rb(b);
			current++;
		}
		else if (a->array[0] <= current + chunk_size)
		{
			do_pb(a, b);
			current++;
		}
		else
			do_ra(a);
	}
}

void	move_max_back_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = find_max_position(b);
		rotate_b_to_top(b, max_pos);
		do_pa(a, b);
	}
}

int	sort_big(t_stack *a, t_stack *b)
{
	int	*sorted_arr;
	int	chunk_size;

	initialize_sort(a, &sorted_arr, &chunk_size);
	move_chunks_to_b(a, b, chunk_size);
	move_max_back_to_a(a, b);
	restore_original_values(a, sorted_arr, a->size);
	free(sorted_arr);
	return (1);
}
