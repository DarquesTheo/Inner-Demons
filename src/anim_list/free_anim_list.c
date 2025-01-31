/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** free_anim_list
*/

#include "anim.h"
#include <stdlib.h>

void free_anim_list(anim_t **list)
{
    anim_t *next = NULL;

    for (; *list; (*list) = next) {
        next = (*list)->next;
        delete_anim(list, *list);
    }
}
