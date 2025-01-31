/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_tilesets
*/

#include "res.h"
#include <stdlib.h>

tilesets_t *init_tilesets(void)
{
    tilesets_t *tilesets = malloc(sizeof(tilesets_t));

    tilesets->floor1 =
    sfTexture_createFromFile("res/map/floor1/tileset.png", NULL);
    tilesets->floor2 =
    sfTexture_createFromFile("res/map/floor2/tileset.png", NULL);
    tilesets->floor3 =
    sfTexture_createFromFile("res/map/floor3/tileset.png", NULL);
    tilesets->floor4 =
    sfTexture_createFromFile("res/map/floor3/tileset.png", NULL);
    tilesets->spawn =
    sfTexture_createFromFile("res/map/spawn/tileset.png", NULL);
    return tilesets;
}
