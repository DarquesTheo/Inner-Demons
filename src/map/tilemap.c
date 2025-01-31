/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** tilemap
*/

#include "game.h"
#include "utils.h"

//can change the color of vertex to give img the colors we want
sfVertexArray *create_vertex_array(int size)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex basic_vertex;

    basic_vertex.color = (sfColor){255, 255, 255, 255};
    for (int i = 0; i < size; i++) {
        sfVertexArray_append(vertex_array, basic_vertex);
    }
    return vertex_array;
}

void load_tilemap2(sfVertex *quad, sfVector2i tutv,
    sfVector2i tile_size, sfVector2i ij)
{
    int i = ij.x;
    int j = ij.y;
    int tu = tutv.x;
    int tv = tutv.y;

    quad[0].position = (sfVector2f){i * tile_size.x, j * tile_size.y};
    quad[1].position = (sfVector2f){(i + 1) * tile_size.x, j * tile_size.y};
    quad[2].position = v2f((i + 1) * tile_size.x, (j + 1) * tile_size.y);
    quad[3].position = (sfVector2f){i * tile_size.x, (j + 1) * tile_size.y};
    quad[0].texCoords = (sfVector2f){tu * tile_size.x, tv * tile_size.y};
    quad[1].texCoords = (sfVector2f){(tu + 1) * tile_size.x, tv * tile_size.y};
    quad[2].texCoords = v2f((tu + 1) * tile_size.x, (tv + 1) * tile_size.y);
    quad[3].texCoords = (sfVector2f){tu * tile_size.x, (tv + 1) * tile_size.y};
}

//tileset, int[]w/map, size of a tile, dim of map
sfVertexArray *load_tilemap(sfTexture *tileset,
    sfVector2i tile_size, int *tiles, sfVector2i dim)
{
    sfVertexArray *map = create_vertex_array(dim.x * dim.y * 4);
    int tile_nb;
    int tu;
    int tv;
    sfVertex *quad;

    sfVertexArray_setPrimitiveType(map, sfQuads);
    for (int i = 0; i < dim.x; i++) {
        for (int j = 0; j < dim.y; j++) {
            tile_nb = tiles[i + j * dim.x];
            tu = tile_nb % ((int)sfTexture_getSize(tileset).x / tile_size.x);
            tv = tile_nb / ((int)sfTexture_getSize(tileset).x / tile_size.x);
            quad = sfVertexArray_getVertex(map, (i + j * dim.x) * 4);
            load_tilemap2(quad, v2i(tu, tv), tile_size, v2i(i, j));
        }
    }
    return map;
}
