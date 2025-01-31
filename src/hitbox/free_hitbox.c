/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** free_hitbox
*/

#include "hitbox.h"
#include <stdlib.h>

void free_hitbox(hitbox_rect_t *hitbox)
{
    sfRectangleShape_destroy(hitbox->rect);
    free(hitbox);
}
