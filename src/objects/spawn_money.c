/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** spawn_piece
*/

#include "map.h"
#include "anim.h"
#include "utils.h"
#include "res.h"
#include "const.h"
#include "system.h"
#include "hitbox.h"
#include "player.h"
#include <string.h>
#include <stdio.h>
#include "sound_manager.h"

int on_money_col(game_t *game, UNUSED anim_t *ani, UNUSED mob_t *mob,
    col_type_t type)
{
    if (type == COL_PLAYER) {
        player_gain_coin(game, ani->dmg);
        play_sound(game, "pick_coin", rand_float(0.8, 1.2));
        return 1;
    }
    return 0;
}

static int get_money_value(char *type)
{
    if (!strcmp(type, "ruby_coin"))
        return 50;
    if (!strcmp(type, "gold_coin"))
        return 10;
    if (!strcmp(type, "silver_coin"))
        return 5;
    if (!strcmp(type, "copper_coin"))
        return 1;
    printf("wrong money value\n");
    return -1;
}

void spawn_money2(game_t *game, anim_t *anim)
{
    anim->hitbox = create_rect_hitbox(v2f(48, 48), v2f(0, 0));
    place_sprite_hitbox(anim->hitbox, anim->sprite);
    anim->layer = 2;
    add_anim(game, anim);
}

void spawn_money(game_t *game, sfVector2f pos, char *type, sfBool sfx)
{
    anim_t *anim = get_default_anim();

    anim->col->player = sfTrue;
    anim->dmg = get_money_value(type);
    if (anim->dmg == -1)
        return;
    if (sfx)
        play_sound(game, "drop_coin", rand_float(0.8, 1.2));
    anim->fps = rand_int(8, 12);
    anim->go_to_player = sfTrue;
    anim->img_width = 80;
    anim->loop = sfTrue;
    anim->on_collide = &on_money_col;
    sfSprite_setTexture(anim->sprite, get_tex(game, type), 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){8, 8});
    sfSprite_setPosition(anim->sprite, pos);
    sfSprite_setScale(anim->sprite, (sfVector2f){3, 3});
    anim->rect = init_intrect(16, 16);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    spawn_money2(game, anim);
}
