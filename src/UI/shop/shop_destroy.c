/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** shop_destroy
*/

#include "shop.h"
#include <stdlib.h>

void shop_destroy(shop_t *shop)
{
    destroy_button(shop->health_btn->btn);
    sfSprite_destroy(shop->health_btn->icon);
    sfText_destroy(shop->health_btn->text);
    sfText_destroy(shop->health_btn->price);
    free(shop->health_btn);
    sfRectangleShape_destroy(shop->window);
    free(shop);
}
