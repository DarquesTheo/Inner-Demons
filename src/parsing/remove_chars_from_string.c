/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** remove_chars_from_string
*/

#include "game.h"

static int is_to_delete(char *str, char *rm, int src)
{
    for (int i = 0; rm[i] != 0; i++) {
        if (str[src] == rm[i]) {
            return 1;
        }
    }
    return 0;
}

void remove_chars(char *str, char *rm)
{
    int dst = 0;

    for (int src = 0; str[src] != 0; src++) {
        if (!is_to_delete(str, rm, src)) {
            str[dst] = str[src];
            dst++;
        }
    }
    str[dst] = 0;
}
