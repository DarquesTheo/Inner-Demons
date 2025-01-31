/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_sbuf
*/

#include "res.h"
#include <string.h>

sfSoundBuffer *get_sbuf(game_t *game, char *name)
{
    if (!name)
        return NULL;
    for (sbuf_list_t *tmp = game->res->sbuf_list; tmp; tmp = tmp->next) {
        if (!strcmp(name, tmp->name))
            return tmp->soundbuffer;
    }
    return NULL;
}
