/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** npc_mage
*/

#include "anim.h"
#include "utils.h"
#include "keybinds.h"
#include "ui.h"
#include "vector.h"
#include "const.h"

//faire sftext sur collide = easy
int npc_mage_col(game_t *game, anim_t *ani,
    UNUSED mob_t *mob, UNUSED col_type_t type)
{
    sfVector2f pos = sfSprite_getPosition(ani->sprite);

    if (game->info->inputs->toggle_shop == sfTrue) {
        game->info->inputs->toggle_shop = sfFalse;
        shop_toggle(game->ui->shop, game);
    }
    sfText_setString(ani->text, "press E to interact");
    sfText_setFont(ani->text, game->res->fonts->dialogue_font);
    sfText_setCharacterSize(ani->text, 15);
    sfText_setOutlineColor(ani->text, sfBlack);
    sfText_setOutlineThickness(ani->text, 3);
    sfText_setPosition(ani->text, add_vectors(pos, v2f(40, 0)));
    return 0;
}

void spawn_mage_npc(game_t *game, sfVector2f pos)
{
    anim_t *anim = get_default_anim();

    anim->fps = 8;
    anim->col->player = sfTrue;
    anim->img_width = 576;
    anim->loop = sfTrue;
    sfSprite_setTexture(anim->sprite, get_tex(game, "npc_mage"), 0);
    sfSprite_setPosition(anim->sprite, pos);
    anim->rect = init_intrect(64, 64);
    sfSprite_setOrigin(anim->sprite, v2f(32, 32));
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    sfSprite_setScale(anim->sprite, v2f(3, 3));
    anim->type = ANIM_NPC;
    anim->hitbox = create_rect_hitbox(v2f(320, 320), v2f(0, 0));
    place_sprite_hitbox(anim->hitbox, anim->sprite);
    anim->on_collide = &npc_mage_col;
    add_anim(game, anim);
}
