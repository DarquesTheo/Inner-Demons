/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** del_sound
*/

#include "game.h"
#include "dialogue.h"
#include <stdlib.h>

void delete_dialogue(dialogue_t **list, dialogue_t *del)
{
    if (*list == NULL || del == NULL)
        return;
    if (*list == del)
        *list = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    sfClock_destroy(del->clock);
    sfText_destroy(del->text);
    sfRectangleShape_destroy(del->rect);
    free(del->str);
    free(del->cur_str);
    sfSprite_destroy(del->sprite);
    free(del);
}
