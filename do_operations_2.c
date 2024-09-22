/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:02:17 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/21 17:42:48 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stack *a)
{
	ra(a);
	ft_putstr("ra\n");
}

void	do_rb(t_stack *b)
{
	rb(b);
	ft_putstr("rb\n");
}

void	do_rra(t_stack *a)
{
	rra(a);
	ft_putstr("rra\n");
}

void	do_rrb(t_stack *b)
{
	rrb(b);
	ft_putstr("rrb\n");
}
