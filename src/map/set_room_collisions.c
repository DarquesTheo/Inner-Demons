/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set_room_collisions
*/

#include "game.h"
#include "map.h"
#include <stdlib.h>
#include <string.h>

void set_room_collisions2(room_t *room, int nb_colliding_tiles,
    int *colliding_tiles, int i)
{
    for (int j = 0; j < nb_colliding_tiles; j++) {
        if (room->int_layer1[i] == colliding_tiles[j]
        || room->int_layer2[i] == colliding_tiles[j]) {
            room->collisions[i] = 1;
            return;
        }
    }
}

static int get_char_number(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}

static void get_int_col(char *fc, int *t)
{
    char *token = NULL;
    int i = 0;

    token = strtok(fc, "\n");
    while (token) {
        t[i] = atoi(token);
        i++;
        token = strtok(NULL, "\n");
    }
}

static int *get_cols_from_file(char *path, int *nb_col)
{
    char *fc = get_file_content(path);
    int nb = get_char_number(fc, '\n');
    int *t = malloc(nb * sizeof(int));

    *nb_col = nb;
    get_int_col(fc, t);
    return t;
}

void set_room_collisions(room_t *room, char *path)
{
    int nb_col;
    int *colliding_tiles = get_cols_from_file(path, &nb_col);

    room->collisions = malloc(sizeof(int) * room->size.x * room->size.y);
    for (int i = 0; i < room->size.x * room->size.y; i++)
        room->collisions[i] = 0;
    for (int i = 0; i < room->size.x * room->size.y; i++) {
        set_room_collisions2(room, nb_col, colliding_tiles, i);
    }
}
