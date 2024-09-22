/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:38:13 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/22 11:01:12 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// Function to swap two numbers
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Quick sort using while loops
void quicksort(int *arr, int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int i = low - 1;
		int j = low;

		while (j < high) {
			if (arr[j] < pivot) {
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

// Create a sorted array
int *create_sorted_array(t_stack *s) {
	int *arr = malloc(s->size * sizeof(int));
	int i = 0;

	while (i < s->size) {
		arr[i] = s->array[i];
		i++;
	}

	quicksort(arr, 0, s->size - 1);

	return arr;
}

// Assign indices to stack elements based on sorted array
void assign_indices(t_stack *a, int *sorted_arr) {
	int i = 0;
	while (i < a->size) {
		int j = 0;
		while (j < a->size) {
			if (a->array[i] == sorted_arr[j]) {
				a->array[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
}

// Optimized sort_big function
int sort_big(t_stack *a, t_stack *b) {
	int *sorted_arr = create_sorted_array(a);
	int total_size = a->size;
	int op_count = 0;

	assign_indices(a, sorted_arr);

	int chunk_size;
	if (total_size <= 100)
		chunk_size = 15;  // Adjusted for optimal performance
	else
		chunk_size = 30;

	int current = 0;

	while (a->size > 0) {
		if (a->array[0] <= current) {
			do_pb(a, b);
			op_count++;

			// Optional optimization: rotate b if necessary
			if (b->size > 1 && b->array[0] < b->array[1]) {
				do_rb(b);
				op_count++;
			}
			current++;
		}
		else if (a->array[0] <= current + chunk_size) {
			do_pb(a, b);
			op_count++;
			current++;
		}
		else {
			do_ra(a);
			op_count++;
		}
	}

	// Push back from B to A
	while (b->size > 0) {
		int max_pos = 0;
		int max_value = b->array[0];
		int i = 1;
		while (i < b->size) {
			if (b->array[i] > max_value) {
				max_value = b->array[i];
				max_pos = i;
			}
			i++;
		}

		if (max_pos <= b->size / 2) {
			while (max_pos > 0) {
				do_rb(b);
				op_count++;
				max_pos--;
			}
		} else {
			while (max_pos < b->size) {
				do_rrb(b);
				op_count++;
				max_pos++;
			}
		}
		do_pa(a, b);
		op_count++;
	}

	// Restore original values in stack A
	int i = 0;
	while (i < total_size) {
		a->array[i] = sorted_arr[a->array[i]];
		i++;
	}

	free(sorted_arr);
	system("leaks push_swap");
	return op_count;
}