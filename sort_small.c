/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sort_small.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: skuznets <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/05 19:57:52 by skuznets		  #+#	#+#			 */
/*   Updated: 2024/09/06 00:56:00 by skuznets		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int	sort_2(t_stack *a)
{
	if (a->array[0] > a->array[1])
	{
		do_sa(a);
		return (1);
	}
	return (0);
}

// Сортировка для трёх элементов
int	sort_3(t_stack *a)
{
	int	op_count;

	op_count = 0;
	if (a->array[0] > a->array[1])
	{
		do_sa(a);
		op_count++;
	}
	if (a->array[1] > a->array[2])
	{
		do_rra(a);
		op_count++;
	}
	if (a->array[0] > a->array[1])
	{
		do_sa(a);
		op_count++;
	}
	return (op_count);
}

int	sort_4(t_stack *a, t_stack *b)
{
	int	op_count;
	int	min_index;

	op_count = 0;
	min_index = find_min_index(a);
	if (min_index == 1)
	{
		do_ra(a);
		op_count++;
	}
	else if (min_index == 2)
	{
		do_ra(a);
		do_ra(a);
		op_count += 2;
	}
	else if (min_index == 3)
	{
		do_rra(a);
		op_count++;
	}
	do_pb(a, b);
	op_count += sort_3(a)+1;
	do_pa(a, b);
	return (++op_count);
}

int	sort_5(t_stack *a, t_stack *b)
{
	int	op_count;
	int	min_index;

	op_count = 0;
	min_index = find_min_index(a);
	if (min_index == 1)
	{
		do_ra(a);
		op_count++;
	}
	else if (min_index == 2)
	{
		do_ra(a);
		do_ra(a);
		op_count += 2;
	}
	else if (min_index == 3)
	{
		do_rra(a);
		do_rra(a);
		op_count += 2;
	}
	else if (min_index == 4)
	{
		do_rra(a);
		op_count++;
	}
	do_pb(a, b);
	op_count++;
	op_count += sort_4(a, b);
	do_pa(a, b);
	op_count++;
	return (op_count);
}

int sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return (no_sort());
	if (a->size == 0 || a->size == 1)
		return (no_sort());
	else if (a->size == 2)
		return (sort_2(a));
	else if (a->size == 3)
		return (sort_3(a));
	else if (a->size == 4)
		return (sort_4(a, b));
	else if (a->size == 5)
		return (sort_5(a, b));
	else if (a->size > 5)
		sort_big(a, b);
	return (0);
}
