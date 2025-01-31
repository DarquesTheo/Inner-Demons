/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** weapons
*/

#include "game.h"
#include "player.h"
#include "anim.h"
#include "objects.h"
#include "enemies.h"
#include "map.h"
#include "utils.h"
#include "const.h"
#include "inventory.h"
#include "ui.h"
#include "vector.h"

int on_weapon_col(game_t *game, UNUSED anim_t *ani, UNUSED mob_t *mob,
    col_type_t type)
{
    if (type == COL_PLAYER) {
        if (!game->player->wp1) {
            game->player->wp1 = ani->wp;
            return 1;
        }
        if (!game->player->wp2) {
            game->player->wp2 = ani->wp;
            return 1;
        }
        if (inventory_additem(game->ui->inventory, ani->wp) == 1)
            return 1;
    }
    return 0;
}

void spawn_weapon(game_t *game, sfVector2f pos, weapon_t *wp, int angle)
{
    anim_t *anim = get_default_anim();
    sfFloatRect rect = sfSprite_getLocalBounds(wp->sprite);
    sfVector2f s = sfSprite_getScale(wp->sprite);
    sfVector2f o = sfSprite_getOrigin(wp->sprite);

    o = mult_vectors(o, s);
    anim->sprite = wp->sprite;
    anim->col->player = sfTrue;
    anim->on_collide = &on_weapon_col;
    anim->wp = wp;
    sfSprite_setPosition(anim->sprite, pos);
    if (angle == -1)
        sfSprite_setRotation(anim->sprite, rand() % 360);
    anim->hitbox = create_rect_hitbox
    (v2f((rect.width) * s.x, (rect.height) * s.y), v2f(0, 0));
    sfRectangleShape_setOrigin(anim->hitbox->rect, o);
    sfRectangleShape_setPosition(anim->hitbox->rect, pos);
    sfRectangleShape_setRotation(anim->hitbox->rect,
    sfSprite_getRotation(anim->sprite));
    add_anim(game, anim);
}
