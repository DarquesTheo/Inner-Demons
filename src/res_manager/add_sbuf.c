/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** add_soundbuffer
*/

#include "res.h"
#include <string.h>
#include <stdlib.h>

void add_sbuf(game_t *game, char *res_path, char *name)
{
    sbuf_list_t *new = malloc(sizeof(sbuf_list_t));

    new->soundbuffer = sfSoundBuffer_createFromFile(res_path);
    if (!new->soundbuffer) {
        free(new);
        return;
    }
    new->name = strdup(name);
    new->prev = NULL;
    new->next = game->res->sbuf_list;
    if (game->res->sbuf_list != NULL)
        game->res->sbuf_list->prev = new;
    game->res->sbuf_list = new;
}
