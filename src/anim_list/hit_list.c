/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** hit_list
*/

#include "anim.h"
#include "game.h"
#include <stdlib.h>

void add_mob_hit(hit_list_t **list, mob_t *mob)
{
    hit_list_t *new = malloc(sizeof(hit_list_t));

    new->mob = mob;
    new->prev = NULL;
    new->next = (*list);
    if ((*list) != NULL)
        (*list)->prev = new;
    (*list) = new;
}
