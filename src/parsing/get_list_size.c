/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_list_size
*/

#include "map.h"

int get_list_size(linked_list_t *list)
{
    int count = 0;

    for (linked_list_t *tmp = list; tmp; tmp = tmp->next) {
        count++;
    }
    return count;
}
