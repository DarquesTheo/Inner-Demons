/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** button_destroy
*/

#include "button.h"

void destroy_button(button_t *btn)
{
    sfRectangleShape_destroy(btn->icon);
    sfRectangleShape_destroy(btn->rect);
    free(btn->color);
    free(btn);
}
