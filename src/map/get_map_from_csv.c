/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_map_from_file
*/

#include "game.h"
#include "mylib.h"
#include <string.h>
#include "map.h"
#include "stdio.h"

sfVector2i read_map_file_csv2(FILE *fp, int *nbs)
{
    size_t len = 0;
    char *line = NULL;
    char *token = NULL;
    int i = 0;
    ssize_t read = getline(&line, &len, fp);
    sfVector2i size = {read / 2, 0};

    while (read != -1) {
        size.y += 1;
        token = strtok(line, ",\n");
        while (token != NULL) {
            nbs[i] = atoi(token);
            i++;
            token = strtok(NULL, ",\n");
        }
        read = getline(&line, &len, fp);
    }
    if (line)
        free(line);
    return size;
}

room_t *read_map_file_csv(char *path)
{
    FILE *fp = fopen(path, "r");
    int *nbs = malloc(get_file_size(path) / 2 * sizeof(int));
    room_t *maptab = malloc(sizeof(room_t));

    if (!nbs) {
        perror("malloc");
        return NULL;
    }
    maptab->size = read_map_file_csv2(fp, nbs);
    maptab->int_layer1 = nbs;
    maptab->layer1 = NULL;
    fclose(fp);
    return maptab;
}
