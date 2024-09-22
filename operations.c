/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:38:41 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/22 10:58:07 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = tmp;
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->array[0];
	b->array[0] = b->array[1];
	b->array[1] = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void pa(t_stack *a, t_stack *b)
{
    int i;

    // Если стек b пуст, ничего не делаем
    if (b->size == 0)
        return;

    // Сдвигаем элементы стека a вправо для освобождения места в начале
    i = a->size;
    while (i > 0)
    {
        a->array[i] = a->array[i - 1];
        i--;
    }

    // Перемещаем верхний элемент из b в a
    a->array[0] = b->array[0];
    a->size++;

    // Сдвигаем элементы стека b влево, удаляя верхний элемент
    i = 0;
    while (i < b->size - 1) // Исправлено условие: i < b->size - 1
    {
        b->array[i] = b->array[i + 1];
        i++;
    }
    b->size--;
}

void pb(t_stack *a, t_stack *b) {
    int i;

    // Если стек a пуст, ничего не делаем
    if (a->size == 0)
        return;

    // Убедитесь, что стек b имеет достаточный размер
    // Предполагается, что память для b->array была выделена заранее

    // Сдвигаем элементы стека b вправо для освобождения места в начале
    i = b->size;
    while (i > 0) {
        b->array[i] = b->array[i - 1];
        i--;
    }

    // Перемещаем верхний элемент из a в b
    b->array[0] = a->array[0];
    b->size++;

    // Сдвигаем элементы стека a влево, удаляя верхний элемент
    i = 0;
    while (i < a->size - 1) { // Изменено условие на i < a->size - 1
        a->array[i] = a->array[i + 1];
        i++;
    }
    a->size--;
}
