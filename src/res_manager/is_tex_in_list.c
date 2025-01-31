/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** is_tex_in_list
*/

#include "res.h"
#include <string.h>
#include <stdio.h>

int is_tex_in_list(tex_list_t *list, char *name)
{
    for (tex_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (!strcmp(name, tmp->name))
            return 1;
    }
    return 0;
}
