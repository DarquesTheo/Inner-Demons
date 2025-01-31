/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** del_sound
*/

#include "sound_manager.h"
#include <stdlib.h>

void delete_sound(sound_manager_t **list, sound_manager_t *del)
{
    if (*list == NULL || del == NULL)
        return;
    if (*list == del)
        *list = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    sfSound_destroy(del->sound);
    free(del);
}
