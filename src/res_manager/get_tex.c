/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_sbuf
*/

#include "res.h"
#include <string.h>
#include <stdio.h>

sfTexture *get_tex(game_t *game, char *name)
{
    for (tex_list_t *tmp = game->res->tex_list; tmp; tmp = tmp->next) {
        if (!strcmp(name, tmp->name))
            return tmp->tex;
    }
    printf("texture %s not found\n", name);
    return NULL;
}

sfTexture *get_tex_from_list(tex_list_t *list, char *name)
{
    for (tex_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (!strcmp(name, tmp->name))
            return tmp->tex;
    }
    printf("texture %s not found\n", name);
    return NULL;
}
