/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:09:24 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/22 12:11:21 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = (int *)malloc(size * sizeof(int));
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->array)
			free(stack->array);
		free(stack);
	}
}

void	load_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i], &value) == 0)
		{
			stack->array[stack->size] = (int)value;
			stack->size++;
		}
		i++;
	}
}
