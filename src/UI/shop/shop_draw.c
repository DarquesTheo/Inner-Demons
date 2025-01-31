/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** shop_draw
*/

#include "shop.h"

static void draw_health_btn(sfRenderWindow *window, shop_t *shop)
{
    sfrenderwindow_drawbutton(window, shop->health_btn->btn);
    sfRenderWindow_drawText(window, shop->health_btn->text, NULL);
    sfRenderWindow_drawSprite(window, shop->health_btn->icon, NULL);
    sfRenderWindow_drawText(window, shop->health_btn->price, NULL);
}

static void draw_dream_btn(sfRenderWindow *window, shop_t *shop)
{
    sfrenderwindow_drawbutton(window, shop->dream_stone->btn);
    sfRenderWindow_drawText(window, shop->dream_stone->text, NULL);
}

void draw_coin(sfRenderWindow *window, shop_t *shop)
{
    sfRenderWindow_drawText(window, shop->coin_text, NULL);
    sfRenderWindow_drawSprite(window, shop->coin_icon, NULL);
}

void sfrenderwindow_drawshop(sfRenderWindow *window, shop_t *shop)
{
    if (shop->visible == sfFalse)
        return;
    sfRenderWindow_drawRectangleShape(window, shop->window, NULL);
    draw_health_btn(window, shop);
    draw_dream_btn(window, shop);
}
