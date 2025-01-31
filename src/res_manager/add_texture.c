/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** add_soundbuffer
*/

#include "res.h"
#include <string.h>
#include <stdlib.h>

void add_tex(game_t *game, char *res_path, char *name)
{
    tex_list_t *new = malloc(sizeof(tex_list_t));

    new->tex = sfTexture_createFromFile(res_path, NULL);
    if (!new->tex) {
        free(new);
        return;
    }
    new->name = strdup(name);
    new->prev = NULL;
    new->next = game->res->tex_list;
    if (game->res->tex_list != NULL)
        game->res->tex_list->prev = new;
    game->res->tex_list = new;
}
