#include "push_swap.h"
#include <stdio.h>

// Функция для проверки корректности входных данных
int is_number(const char *str) {
    if (*str == '-' || *str == '+')
        str++;
    while (*str) {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

// Парсинг аргументов и инициализация стека a
void parse_arguments(t_stack *a, int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (!is_number(argv[i])) {
            write(2, "Error\n", 6);
            exit(EXIT_FAILURE);
        }
        a->array[a->size++] = atoi(argv[i]);
    }
}

// Пример сортировочной функции
void sort(t_stack *a) {
    // Реализуем простой пузырьковый алгоритм сортировки
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < a->size - 1; i++) {
            if (a->array[i] > a->array[i + 1]) {
                sa(a);
                write(1, "sa\n", 3);
                swapped = 1;
            }
            ra(a);
            write(1, "ra\n", 3);
        }
        if (!swapped) break;
        for (int i = 0; i < a->size - 1; i++) {
            rra(a);
            write(1, "rra\n", 4);
        }
    } while (swapped);
}

int main(int argc, char **argv) {
    if (argc < 2)
        return 0;

    t_stack *a = init_stack(argc - 1);
    t_stack *b = init_stack(argc - 1);
    if (!a || !b) {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }

    parse_arguments(a, argc, argv);

    // Основная логика сортировки
    sort(a, b);

    // Освобождение памяти
    free_stack(a);
    free_stack(b);
    return 0;
}