/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** is_mob_in_hit_list
*/

#include "anim.h"

int is_mob_in_hit_list(hit_list_t *list, mob_t *mob)
{
    if (!mob)
        return -1;
    for (hit_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (tmp->mob == mob)
            return 1;
    }
    return 0;
}
