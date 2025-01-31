/*
** EPITECH PROJECT, 2024
** atoi.c
** File description:
** atoi
*/

#include <stdlib.h>

static int my_atoi2(int value)
{
    int size = 0;

    if (value < 0)
        size++;
    for (; value != 0; value = value / 10) {
        if (value == 10)
            value = 11;
        size++;
    }
    if (size == 0)
        size++;
    return size;
}

char *my_atoi(int value)
{
    char *str;
    int power = 1;
    int i = 0;
    int size = my_atoi2(value);

    str = malloc(sizeof(char) * (size + 2));
    if (value < 0) {
        value = -value;
        str[0] = '-';
        i++;
    }
    for (int j = 1; j + i < size; j++)
        power = power * 10;
    for (; i < size; i++) {
        str[i] = (value / power) + 48;
        value = value % power;
        power = power / 10;
    }
    str[size] = 0;
    return str;
}
