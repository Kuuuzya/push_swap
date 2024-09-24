/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:13:36 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/24 15:24:44 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	validate_args(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc == 2 && (argv[1][0] == '\0' || is_whitespace_only(argv[1])))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	count_total_args(int argc, char *argv[])
{
	int		total_args;
	int		i;
	int		j;
	char	**split;

	i = 1;
	total_args = 0;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		if (!split)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		j = 0;
		while (split[j])
		{
			total_args++;
			free(split[j++]);
		}
		free(split);
	}
	return (total_args);
}

char	**combine_args(int argc, char *argv[], int total_args)
{
	char	**args;
	int		i;
	int		j;
	int		k;
	char	**split;

	args = (char **)malloc((total_args + 2) * sizeof(char *));
	if (!args)
		return (write(2, "Error\n", 6), NULL);
	args[0] = argv[0];
	j = 1;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		k = 0;
		while (split && split[k])
			args[j++] = split[k++];
		free(split);
	}
	args[j] = NULL;
	return (args);
}

int	initialize_and_sort(int total_args, char **args)
{
	t_stack	*a;
	t_stack	*b;
	int		j;

	j = 0;
	while (args[j])
		j++;
	if (check(j, args) != 0)
		return (free_args(args, j), 1);
	a = init_stack(total_args);
	b = init_stack(total_args);
	if (!a || !b)
		return (free_all(a, b, args, j), 1);
	load_stack(a, j, args);
	sort(a, b);
	free_all(a, b, args, j);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**args;
	int		total_args;

	if (validate_args(argc, argv) != 0)
		return (1);
	total_args = count_total_args(argc, argv);
	if (total_args == -1)
		return (1);
	if (total_args == 0)
		return (0);
	args = combine_args(argc, argv, total_args);
	if (!args)
		return (1);
	if (initialize_and_sort(total_args, args) != 0)
		return (1);
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