/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** delete_sbuf
*/

#include "res.h"
#include <stdlib.h>

void delete_sbuf(sbuf_list_t **list, sbuf_list_t *del)
{
    if (*list == NULL || del == NULL)
        return;
    if (*list == del)
        *list = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    sfSoundBuffer_destroy(del->soundbuffer);
    free(del->name);
    free(del);
}
