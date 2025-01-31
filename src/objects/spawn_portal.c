/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** spawn_portal
*/

#include "map.h"
#include "anim.h"
#include "utils.h"
#include "res.h"
#include "const.h"
#include "system.h"
#include "hitbox.h"
#include "player.h"
#include "vector.h"
#include <math.h>

int on_portal_col(game_t *game, UNUSED anim_t *ani, UNUSED mob_t *mob,
    col_type_t type)
{
    if (type == COL_PLAYER && game->player->state == DASHING) {
        sfClock_restart(game->system->clock);
        free_anim_list(&(game->anims));
        free_current_map(game);
        change_system_map(game);
        return 2;
    }
    return 0;
}

void set_portal_rotation(game_t *game, anim_t *anim, sfVector2f pos)
{
    sfVector2f dir = get_room_center(game->map);
    sfVector2f dif_vec = get_vector_difference(dir, pos);

    sfSprite_setRotation(anim->sprite,
    atan2(dif_vec.y, dif_vec.x) / PI * 180);
}

int spawn_portal(game_t *game, sfVector2f pos)
{
    anim_t *anim = get_default_anim();

    anim->col->player = sfTrue;
    anim->fps = 20;
    anim->img_width = 2880;
    anim->duration = -1;
    anim->loop = sfTrue;
    anim->on_collide = &on_portal_col;
    sfSprite_setTexture(anim->sprite,
    game->res->obj_res->portal_blue, 0);
    set_portal_rotation(game, anim, pos);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){160, 160});
    sfSprite_setPosition(anim->sprite, pos);
    anim->rect = init_intrect(320, 320);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->move = v2f(0.0f, 0.0f);
    anim->hitbox = create_rect_hitbox(v2f(100, 100), v2f(0, 0));
    place_sprite_hitbox(anim->hitbox, anim->sprite);
    add_anim(game, anim);
    return 1;
}
