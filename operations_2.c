/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:44:33 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/21 16:56:23 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *a)
{
    int tmp;
    int i;

    if (a->size < 2)
        return;
    // Сохраняем первый элемент стека
    tmp = a->array[0];
    
    // Сдвигаем все элементы вверх
    i = 0;
    while (i < a->size - 1)
    {
        a->array[i] = a->array[i + 1];
        i++;
    }
    
    // Переносим сохраненный элемент в конец стека
    a->array[a->size - 1] = tmp;
}

void rb(t_stack *b)
{
    int tmp;
    int i;

    if (b->size < 2)
        return;
    // Сохраняем первый элемент стека
    tmp = b->array[0];
    
    // Сдвигаем все элементы вверх
    i = 0;
    while (i < b->size - 1)
    {
        b->array[i] = b->array[i + 1];
        i++;
    }

    // Переносим сохраненный элемент в конец стека
    b->array[b->size - 1] = tmp;
}

void rra(t_stack *a)
{
    int tmp;
    int i;

    if (a->size < 2)
        return;
    // Сохраняем последний элемент стека
    tmp = a->array[a->size - 1];
    
    // Сдвигаем все элементы вниз
    i = a->size - 1;
    while (i > 0)
    {
        a->array[i] = a->array[i - 1];
        i--;
    }
    
    // Переносим сохраненный элемент в начало стека
    a->array[0] = tmp;

    // Выводим "rra" для этой операции
}

void rrb(t_stack *b)
{
    int tmp;
    int i;

    if (b->size < 2)
        return;
    // Сохраняем последний элемент стека
    tmp = b->array[b->size - 1];
    
    // Сдвигаем все элементы вниз
    i = b->size - 1;
    while (i > 0)
    {
        b->array[i] = b->array[i - 1];
        i--;
    }

    // Переносим сохраненный элемент в начало стека
    b->array[0] = tmp;

    // Выводим "rrb" для этой операции
}
