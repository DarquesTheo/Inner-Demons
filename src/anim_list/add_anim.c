/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** add_anim
*/

#include "game.h"
#include "anim.h"

//anim is an anim with no defined prev or next
void add_anim(game_t *game, anim_t *anim)
{
    anim->prev = NULL;
    anim->next = game->anims;
    if (game->anims != NULL)
        game->anims->prev = anim;
    game->anims = anim;
}

void add_anim_to_list(anim_t **list, anim_t *anim)
{
    anim->prev = NULL;
    anim->next = *list;
    if (*list != NULL)
        (*list)->prev = anim;
    *list = anim;
}
