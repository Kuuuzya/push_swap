/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:14:55 by skuznets          #+#    #+#             */
/*   Updated: 2024/09/05 22:48:08 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

long ft_atoi(const char *str, long *out)
{
    long res = 0;
    int sign = 1;

    while (ft_isspace(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (!ft_isdigit(*str)) // Проверка на пустую строку после знака
        return 1;

    while (ft_isdigit(*str))
    {
        res = res * 10 + (*str - '0');
        // Проверка на переполнение диапазона `int`
        if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
            return 1;
        str++;
    }

    if (*str != '\0') // Проверка на наличие нецифровых символов
        return 1;

    *out = res * sign;
    return 0;
}