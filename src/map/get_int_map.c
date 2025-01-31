/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_int_map
*/

#include "map.h"
#include <stdlib.h>
#include <string.h>

int *get_int_map(char *map, sfVector2i dim)
{
    int *int_map = malloc(sizeof(int) * dim.x * dim.y);
    char *token = NULL;
    int i = 0;

    token = strtok(map, ",\0");
    while (token) {
        int_map[i] = atoi(token) - 1;
        if (int_map[i] == -1)
            int_map[i] = 10000;
        i++;
        token = strtok(NULL, ",\0");
    }
    return int_map;
}
