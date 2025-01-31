/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** do_collide_function
*/

#include "game.h"
#include "anim.h"

//return true if the anim is deleted
int do_collide_function(anim_t *anim, game_t *game, mob_t *mob,
    col_type_t type)
{
    int del_state = 0;

    del_state = anim->on_collide(game, anim, mob, type);
    if (del_state == 0 && type == COL_WALL)
        del_state = 1;
    if (del_state == 1) {
        delete_anim(&(game->anims), anim);
    }
    return del_state;
}
