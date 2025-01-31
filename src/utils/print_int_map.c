/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** print_int_map
*/

#include "game.h"
#include "map.h"
#include <stdio.h>

static void print_line(int x)
{
    for (int i = 0; i < x; i++) {
        printf("-");
    }
}

void print_int_map(int *map, sfVector2i size)
{
    printf("|");
    print_line(size.x);
    printf("|\n|");
    for (int i = 0; i < size.x * size.y; i++) {
        if (map[i] == -1)
            printf(" ");
        else
            printf("%d", map[i]);
        if ((i + 1) % size.x == 0)
            printf("|\n|");
    }
    print_line(size.x);
    printf("|\n");
}
