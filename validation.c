/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:53:41 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/05 22:50:10 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int has_duplicates(int argc, char **argv)
{
    int i, j;
    long num_i, num_j;

    i = 1;
    while (i < argc)
    {
        // Конвертация строки в число через ft_atoi
        if (ft_atoi(argv[i], &num_i) != 0)
            return 1; // Если вдруг ошибка, возвращаем 1 (это можно оставить для безопасности)

        j = i + 1;
        while (j < argc)
        {
            // Конвертация строки в число через ft_atoi
            if (ft_atoi(argv[j], &num_j) != 0)
                return 1; // Аналогично проверяем второе число

            if (num_i == num_j)
                return 1; // Найден дубликат

            j++;
        }
        i++;
    }
    return 0;
}