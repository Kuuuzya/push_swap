#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

// Структура для представления стека
typedef struct	s_stack {
	int	*array;
	int	size;
} t_stack;

// Функции для работы со стеком
t_stack	*init_stack(int size);
void	free_stack(t_stack *stack);

// Операции над стеками
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void sort(t_stack *a, t_stack *b);

#endif