/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:58:02 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/21 17:42:26 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack *a)
{
	sa(a);
	ft_putstr("sa\n");
}

void	do_sb(t_stack *b)
{
	sb(b);
	ft_putstr("sb\n");
}

void	do_ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_putstr("ss\n");
}

void	do_pa(t_stack *a, t_stack *b)
{
	pa(a, b);
	ft_putstr("pa\n");
}

void	do_pb(t_stack *a, t_stack *b)
{
	pb(a, b);
	ft_putstr("pb\n");
}
