/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:13:36 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/22 13:19:22 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(int argc, char *argv[])
{
	int		i;
	long	value;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (ft_atoi(argv[i], &value) != 0)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	if (has_duplicates(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (check(argc, argv) != 0)
		return (1);
	a = init_stack(argc - 1);
	b = init_stack(argc - 1);
	if (!a || !b)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	load_stack(a, argc, argv);
	sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

	//Output
	//printf("\n\n RESULT \n");
	//int j = 0;
	//while (j < a->size)
	//{
	//printf("%d ", a->array[j]);
	//j++;
	//}
	//printf("\n");