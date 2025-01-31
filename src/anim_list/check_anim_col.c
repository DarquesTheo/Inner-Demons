/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** check_anim_col
*/

#include "game.h"
#include "vector.h"
#include "anim.h"
#include "objects.h"
#include "vector.h"
#include "utils.h"
#include "enemies.h"
#include "map.h"
#include "hitbox.h"
#include "player.h"
#include "const.h"

static int anim_w_enemies_col2(game_t *game, anim_t *anim, mob_t *tmp)
{
    if (are_rect_colliding(anim->hitbox->rect, tmp->hitbox->rect)
        && tmp->statut != DYING) {
        if (do_collide_function(anim, game, tmp, COL_ENEMY)) {
            return 1;
        }
    }
    return 0;
}

static int anim_w_enemies_col(game_t *game, anim_t *anim)
{
    for (mob_t *tmp = game->map->mobs; tmp; tmp = tmp->next) {
        if (anim_w_enemies_col2(game, anim, tmp))
            return 1;
    }
    return 0;
}

static int anim_w_object_col3(game_t *game, anim_t *anim, anim_t *tmp)
{
    if (tmp->on_collide(game, tmp, NULL, COL_PPROJ)) {
        if (do_collide_function(anim, game, NULL, COL_OBJ)) {
            return 1;
        }
    }
    return 0;
}

static int anim_w_object_col2(game_t *game, anim_t *anim, anim_t *tmp)
{
    if (are_hitbox_colliding(anim->hitbox, tmp->hitbox)
    && tmp->type == ANIM_OBJ && tmp->col->player_proj == sfTrue) {
        if (anim_w_object_col3(game, anim, tmp)) {
            return 1;
        }
    }
    return 0;
}

static int anim_w_object_col(game_t *game, anim_t *anim)
{
    for (anim_t *tmp = game->anims; tmp; tmp = tmp->next) {
        if (anim_w_object_col2(game, anim, tmp))
            return 1;
    }
    return 0;
}

static int anim_w_player_col(game_t *game, anim_t *anim)
{
    if (are_rect_colliding(anim->hitbox->rect, game->player->hitbox->rect)) {
        return 1;
    }
    return 0;
}

int check_anim_col(game_t *game, anim_t *anim)
{
    sfVector2f pos = sfSprite_getPosition(anim->sprite);

    if (anim && anim->col->map) {
        if (get_tile_point_col(game, pos) == 1)
            return do_collide_function(anim, game, NULL, COL_WALL);
    }
    if (anim && anim->col->object) {
        if (anim_w_object_col(game, anim))
            return 1;
    }
    if (anim && anim->col->ennemy) {
        if (anim_w_enemies_col(game, anim))
            return 1;
    }
    if (anim && anim->col->player) {
        if (anim_w_player_col(game, anim))
            return do_collide_function(anim, game, NULL, COL_PLAYER);
    }
    return 0;
}
