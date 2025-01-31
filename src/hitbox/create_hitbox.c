/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** create_hitbox.c
*/

#include "hitbox.h"
#include "utils.h"
#include <stdlib.h>

//hitbox with origin in middle of rectangle
hitbox_rect_t *create_rect_hitbox(sfVector2f size, sfVector2f offset)
{
    hitbox_rect_t *hitbox = malloc(sizeof(hitbox_rect_t));

    hitbox->offset = offset;
    hitbox->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(hitbox->rect, size);
    sfRectangleShape_setOrigin(hitbox->rect, v2f(size.x / 2, size.y / 2));
    sfRectangleShape_setFillColor(hitbox->rect, (sfColor){39, 245, 255, 100});
    sfRectangleShape_setFillColor(hitbox->rect, (sfColor){39, 245, 255, 100});
    sfRectangleShape_setOutlineColor
    (hitbox->rect, (sfColor){29, 84, 255, 255});
    return hitbox;
}
