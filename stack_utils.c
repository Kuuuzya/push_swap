/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:43:30 by skuznets          #+#    #+#             */
/*   Updated: 2024/06/16 17:52:15 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(int size) {
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->array = (int *)malloc(size * sizeof(int));
    if (!stack->array) {
        free(stack);
        return NULL;
    }
    stack->size = 0;
    return stack;
}

// Освобождение памяти стека
void free_stack(t_stack *stack) {
    if (stack) {
        if (stack->array)
            free(stack->array);
        free(stack);
    }
}