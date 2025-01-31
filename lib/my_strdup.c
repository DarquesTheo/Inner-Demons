/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** task 01
*/

#include "mylib.h"
#include <stdlib.h>

char *my_strndup(char const *src, int n)
{
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * (n + 1));
    while (i < n) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * my_strlen(src) + 1);
    while (i < my_strlen(src)) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
