/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_map_from_lua
*/

#include "game.h"
#include "mylib.h"
#include <string.h>
#include "map.h"
#include "res.h"
#include "objects.h"
#include "utils.h"
#include <stdlib.h>
#include "vector.h"

sfVector2i get_rand_pos_in_room(room_t *room)
{
    sfVector2i t = room->tilesize;
    sfVector2f s = room->scale;
    sfVector2i r = v2i(
        rand() % (int)(room->size.x * t.x * s.x),
        rand() % (int)(room->size.y * t.y * s.y));

    return r;
}

sfVector2f get_room_center(room_t *room)
{
    sfVector2f t = v2f(room->tilesize.x, room->tilesize.y);
    sfVector2f s = room->scale;
    sfVector2f size = mult_vectors(t, s);
    sfVector2f room_size = mult_vectors(v2f(room->size.x, room->size.y), size);

    return v2f(room_size.x / 2, room_size.y / 2);
}

void get_map_from_lua2(room_t *room, char *file, game_t *game)
{
    room->player = v2f(0, 0);
    room->portal = v2f(0, 0);
    init_room_objects(file, game, room);
    if (room->player.x == 0 || room->player.y == 0)
        room->player = get_room_center(room);
    if (room->portal.x == 0 || room->portal.y == 0)
        room->portal = get_room_center(room);
    free(file);
}

room_t *get_map_from_lua(char *path_to_lua, game_t *game)
{
    room_t *room = malloc(sizeof(room_t));
    char *file = get_file_content(path_to_lua);
    char *map_data_pos = strchr(strstr(file, "data"), '=') + 2;
    char *map_data = get_text_between_curlys(map_data_pos);

    room->scale = (sfVector2f){5, 5};
    room->transform = (sfVector2f){0, 0};
    room->tilesize = (sfVector2i){atoi(get_lua_variable_value
    (file, "tilewidth")), atoi(get_lua_variable_value(file, "tileheight"))};
    room->size = (sfVector2i){atoi(get_lua_variable_value(file, "width")),
    atoi(get_lua_variable_value(file, "height"))};
    remove_chars(map_data, " \t\n\r");
    room->int_layer1 = get_int_map(map_data, room->size);
    map_data_pos = strchr(strstr(map_data_pos, "data"), '=') + 2;
    map_data = get_text_between_curlys(map_data_pos);
    remove_chars(map_data, " \t\n\r");
    room->int_layer2 = get_int_map(map_data, room->size);
    get_map_from_lua2(room, file, game);
    return room;
}
