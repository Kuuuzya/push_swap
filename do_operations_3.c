/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:04:13 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/21 17:43:03 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr(t_stack *a, t_stack *b)
{
	rr(a, b);
	ft_putstr("rr\n");
}

void	do_rrr(t_stack *a, t_stack *b)
{
	rrr(a, b);
	ft_putstr("rrr\n");
}