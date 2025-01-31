/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** spawn_bed
*/

#include "anim.h"
#include "utils.h"
#include "keybinds.h"
#include "ui.h"
#include "vector.h"
#include "const.h"
#include "system.h"

int bed_col(game_t *game, anim_t *ani,
    UNUSED mob_t *mob, UNUSED col_type_t type)
{
    sfVector2f pos = sfSprite_getPosition(ani->sprite);

    if (game->info->inputs->toggle_shop == sfTrue) {
        game->info->inputs->toggle_shop = sfFalse;
        start_first_map(game);
        return 1;
    }
    sfText_setString(ani->text, "press E to interact");
    sfText_setFont(ani->text, game->res->fonts->dialogue_font);
    sfText_setCharacterSize(ani->text, 15);
    sfText_setOutlineColor(ani->text, sfBlack);
    sfText_setOutlineThickness(ani->text, 3);
    sfText_setPosition(ani->text, add_vectors(pos, v2f(155, 130)));
    return 0;
}

void spawn_bed(game_t *game, sfVector2f pos)
{
    anim_t *anim = get_default_anim();

    anim->col->player = sfTrue;
    anim->loop = sfTrue;
    sfSprite_setPosition(anim->sprite, pos);
    anim->type = ANIM_BED;
    anim->hitbox = create_rect_hitbox(v2f(320, 320), v2f(0, 0));
    sfRectangleShape_setOrigin(anim->hitbox->rect, v2f(0, 0));
    place_sprite_hitbox(anim->hitbox, anim->sprite);
    anim->on_collide = &bed_col;
    add_anim(game, anim);
}
