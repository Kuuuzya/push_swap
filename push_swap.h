/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:02:51 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/23 15:52:12 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*array;
	int	size;
}	t_stack;

t_stack	*init_stack(int size);
void	free_stack(t_stack *stack);
void	load_stack(t_stack *stack, int argc, char **argv);

// operations
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

// print
void	do_sa(t_stack *a);
void	do_sb(t_stack *b);
void	do_ss(t_stack *a, t_stack *b);
void	do_pa(t_stack *a, t_stack *b);
void	do_pb(t_stack *a, t_stack *b);
void	do_ra(t_stack *a);
void	do_rb(t_stack *b);
void	do_rr(t_stack *a, t_stack *b);
void	do_rra(t_stack *a);
void	do_rrb(t_stack *b);
void	do_rrr(t_stack *a, t_stack *b);

//Sort
int		is_sorted(t_stack *a);
int		find_max_index(t_stack *a);
int		find_min_index(t_stack *a);
int		sort(t_stack *a, t_stack *b);
int		sort_3(t_stack *a);
int		is_sorted(t_stack *a);
int		sort_big(t_stack *a, t_stack *b);
void	swap(int *a, int *b);
void	quicksort(int *arr, int low, int high);
int		*create_sorted_array(t_stack *s);
void	restore_original_values(t_stack *a, int *sorted_arr, int total_size);
void	assign_indices(t_stack *a, int *sorted_arr);
int		find_max_position(t_stack *b);
void	rotate_b_to_top(t_stack *b, int max_pos);

// Verification
int		has_duplicates(int argc, char **argv);
int		is_integer(const char *str);
long	ft_atoi(const char *str, long *value);
void	ft_putstr(char const *s);
int		ft_isdigit(int c);
#endif
