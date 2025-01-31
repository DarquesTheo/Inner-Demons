/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** del_anim
*/

#include "anim.h"
#include <stdlib.h>
#include "player.h"

void delete_anim(anim_t **list, anim_t *del)
{
    if (*list == NULL || del == NULL)
        return;
    if (*list == del)
        *list = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    sfClock_destroy(del->clock);
    if (!del->wp)
        sfSprite_destroy(del->sprite);
    free(del);
}
