/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** sort_anim_list
*/

#include "anim.h"

void anim_y_sort_add(anim_t **list, anim_t *anim)
{
    float ypos = sfSprite_getPosition(anim->sprite).y;
    anim_t *current = *list;

    if (*list == NULL || sfSprite_getPosition((*list)->sprite).y >= ypos) {
        anim->next = *list;
        anim->prev = NULL;
        if (*list != NULL)
            (*list)->prev = anim;
        *list = anim;
    } else {
        while (current->next != NULL
        && sfSprite_getPosition(current->next->sprite).y < ypos) {
            current = current->next;
        }
        anim->next = current->next;
        if (current->next != NULL)
            current->next->prev = anim;
        current->next = anim;
        anim->prev = current;
    }
}
