/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set_room_objects
*/

#include "game.h"
#include "map.h"
#include "objects.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "vector.h"
#include "res.h"
#include "utils.h"
#include "anim.h"

static void handle_object(room_t *room, char *name, sfVector2f pos,
    game_t *game)
{
    if (!strcmp(name, "spike")) {
        return add_spike(&(room->objects->spikes), pos,
        game->res->obj_res->spike);
    }
    if (!strcmp(name, "player")) {
        room->player = v2f(pos.x, pos.y);
        return;
    }
    if (!strcmp(name, "portal")) {
        room->portal = v2f(pos.x, pos.y);
        return;
    }
    if (!strcmp(name, "npc"))
        return spawn_mage_npc(game, pos);
    if (!strcmp(name, "wp1") || !strcmp(name, "wp2"))
        return spawn_random_weapon(game, pos, 0);
    if (!strcmp(name, "bed"))
        return spawn_bed(game, pos);
    if (is_tex_in_list(game->res->tex_list, name))
        add_object(game, name, pos);
}

static void set_objects_from_lua(room_t *room, char *file,
    game_t *game)
{
    sfVector2f scale = room->scale;
    char *pos = strstr(file, "objects = {");
    char *name;
    sfVector2f obj_pos;

    pos = strstr(pos, "name = ");
    while (pos != NULL) {
        name = get_lua_variable_value(pos, "name =");
        rm_char_from_str(name, '\"');
        obj_pos.x = atoi(get_lua_variable_value(pos, "x =")) * scale.x;
        obj_pos.y = atoi(get_lua_variable_value(pos, "y =")) * scale.y;
        handle_object(room, name, obj_pos, game);
        pos = strstr(pos + 1, "name = ");
    }
}

void init_room_objects(char *file, game_t *game, room_t *room)
{
    room->objects = malloc(sizeof(objects_t));
    room->objects->pots = NULL;
    room->objects->spikes = NULL;
    set_objects_from_lua(room, file, game);
}
