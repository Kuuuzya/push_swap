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

int	sort_3(t_stack *a)
{
	if (a->array[0] > a->array[1])
		do_sa(a);
	if (a->array[1] > a->array[2])
		do_rra(a);
	if (a->array[0] > a->array[1])
		do_sa(a);
	return (1);
}

int	sort_4(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_min_index(a);
	if (min_index == 1)
		do_ra(a);
	else if (min_index == 2)
	{
		do_ra(a);
		do_ra(a);
	}
	else if (min_index == 3)
		do_rra(a);
	do_pb(a, b);
	sort_3(a);
	do_pa(a, b);
	return (1);
}

int	sort_5(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_min_index(a);
	if (min_index == 1)
		do_ra(a);
	else if (min_index == 2)
	{
		do_ra(a);
		do_ra(a);
	}
	else if (min_index == 3)
	{
		do_rra(a);
		do_rra(a);
	}
	else if (min_index == 4)
		do_rra(a);
	do_pb(a, b);
	sort_4(a, b);
	do_pa(a, b);
	return (1);
}

int	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return (0);
	if (a->size == 0 || a->size == 1)
		return (0);
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
