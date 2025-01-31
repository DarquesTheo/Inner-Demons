/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** move_player
*/

#include "player.h"
#include "vector.h"
#include "objects.h"
#include "map.h"
#include "utils.h"
#include "anim.h"
#include <stdlib.h>

static void set_blocked_dep(sfVector2f *dep,
    sfVector2i cur_tile, sfVector2i next_tile)
{
    int horizontal = sfFalse;
    int vertical = sfFalse;

    if (cur_tile.y != next_tile.y)
        vertical = sfTrue;
    if (cur_tile.x != next_tile.x)
        horizontal = sfTrue;
    if (horizontal)
        dep->x = 0;
    if (vertical)
        dep->y = 0;
}

static void calc_dep_col(game_t *game, sfVector2f pos, sfVector2f *dep)
{
    sfVector2i cur_tile = get_pos_tile(game->map, pos);
    sfVector2f next_ppos = add_vectors(pos, *dep);
    sfVector2i next_tile = get_pos_tile(game->map, next_ppos);

    if (get_tile_point_col(game, next_ppos)) {
        set_blocked_dep(dep, cur_tile, next_tile);
    }
}

static sfVector2f get_final_player_dep(game_t *game, float delta)
{
    int nb_point_by_edge = 3;
    sfRectangleShape *hitbox = game->player->dep_hitbox->rect;
    sfVector2f *rect_point_list =
    get_rectangle_points(nb_point_by_edge, hitbox);
    sfVector2f dep = get_player_delta_vector(game, delta);

    for (int i = 0; i < nb_point_by_edge * 4; i++) {
        calc_dep_col(game, rect_point_list[i], &dep);
    }
    free(rect_point_list);
    return dep;
}

void move_player(game_t *game, float delta)
{
    sfVector2f dep = get_final_player_dep(game, delta);

    sfSprite_move(game->player->sprite, dep);
    place_sprite_hitbox(game->player->dep_hitbox, game->player->sprite);
    place_sprite_hitbox(game->player->hitbox, game->player->sprite);
    player_w_spike_col(game);
}
