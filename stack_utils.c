/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:43:30 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/05 22:49:44 by skuznets         ###   ########.fr       */
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

void load_stack(t_stack *stack, int argc, char **argv)
{
    int i = 1;
    long value;

    while (i < argc) {
        // Используем ft_atoi для конвертации строки в число
        if (ft_atoi(argv[i], &value) == 0) {
            stack->array[stack->size] = (int)value;
            stack->size++;
        }
        i++;
    }
}