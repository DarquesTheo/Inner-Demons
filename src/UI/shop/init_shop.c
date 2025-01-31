/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_shop
*/

#include "shop.h"

static void init_health_btn_visual(shop_button_t *btn, res_t *res)
{
    btn->text = sfText_create();
    sfText_setString(btn->text, "Buy x1");
    sfText_setPosition(btn->text, (sfVector2f){SHOPPOS_X + 135,
        SHOPPOS_Y + 230});
    sfText_setFont(btn->text, res->inv->font);
    sfText_setColor(btn->text, sfBlack);
    btn->price = sfText_create();
    sfText_setString(btn->price, "for 50");
    sfText_setPosition(btn->price, (sfVector2f){SHOPPOS_X + 355,
        SHOPPOS_Y + 230});
    sfText_setFont(btn->price, res->inv->font);
    sfText_setColor(btn->price, sfYellow);
    btn->icon = sfSprite_create();
    sfSprite_setTexture(btn->icon, res->inv->heart_full, 0);
    sfSprite_setPosition(btn->icon, (sfVector2f){SHOPPOS_X + 260,
        SHOPPOS_Y + 210});
    sfSprite_setScale(btn->icon, (sfVector2f){5, 5});
}

shop_button_t *init_health_btn(res_t *res)
{
    shop_button_t *btn = malloc(sizeof(shop_button_t));

    btn->btn = button_create_default();
    button_setposition(btn->btn, (sfVector2f){SHOPPOS_X + 25,
        SHOPPOS_Y + 150});
    button_setsize(btn->btn, (sfVector2f){550, 200});
    button_seticon(btn->btn, res->inv->shopbtn);
    button_seticoncolor(btn->btn, sfWhite);
    button_set_colors(btn->btn, sfTransparent, sfTransparent, sfTransparent);
    init_health_btn_visual(btn, res);
    button_setcallback(btn->btn, (void *)(void *)&buy_health);
    return btn;
}

static void init_dream_btn_visual(shop_button_t *btn, res_t *res)
{
    btn->text = sfText_create();
    sfText_setString(btn->text, "Open dream forge");
    sfText_setPosition(btn->text, (sfVector2f){SHOPPOS_X + 135,
        SHOPPOS_Y + 480});
    sfText_setFont(btn->text, res->inv->font);
    sfText_setColor(btn->text, sfBlack);
}

static shop_button_t *init_dream_stone_btn(res_t *res)
{
    shop_button_t *btn = malloc(sizeof(shop_button_t));

    btn->btn = button_create_default();
    button_setposition(btn->btn, (sfVector2f){SHOPPOS_X + 25,
        SHOPPOS_Y + 400});
    button_setsize(btn->btn, (sfVector2f){550, 200});
    button_seticon(btn->btn, res->inv->shopbtn);
    button_seticoncolor(btn->btn, sfWhite);
    button_set_colors(btn->btn, sfTransparent, sfTransparent, sfTransparent);
    init_dream_btn_visual(btn, res);
    button_setcallback(btn->btn, (void *)(void *)&open_dream_forge);
    return btn;
}

static void init_coin(res_t *res, shop_t *shop)
{
    shop->coin_text = sfText_create();
    sfText_setPosition(shop->coin_text, (sfVector2f){COIN_TEXT_POS_X,
        COIN_TEXT_POS_Y});
    sfText_setFont(shop->coin_text, res->inv->font);
    sfText_setCharacterSize(shop->coin_text, COIN_TEXT_SIZE);
    sfText_setOutlineColor(shop->coin_text, COIN_OUTLINE_COLOR);
    sfText_setOutlineThickness(shop->coin_text, COIN_OUTLINE_THICKNESS);
    sfText_setFillColor(shop->coin_text, COIN_FILL_COLOR);
    sfText_setString(shop->coin_text, "0");
    shop->coin_icon = sfSprite_create();
    sfSprite_setTexture(shop->coin_icon, res->inv->coin, 0);
    sfSprite_setPosition(shop->coin_icon, (sfVector2f){COIN_LOGO_POS_X,
        COIN_LOGO_POS_Y});
    sfSprite_setScale(shop->coin_icon, (sfVector2f){COIN_LOGO_SCALE,
        COIN_LOGO_SCALE});
}

shop_t *init_shop(res_t *res)
{
    shop_t *shop = malloc(sizeof(shop_t));

    shop->visible = sfFalse;
    shop->window = sfRectangleShape_create();
    sfRectangleShape_setSize(shop->window, (sfVector2f){SHOPSIZE_X,
        SHOPSIZE_Y});
    sfRectangleShape_setPosition(shop->window, (sfVector2f){SHOPPOS_X - 150,
        SHOPPOS_Y});
    sfRectangleShape_setTexture(shop->window, res->inv->shop_bg, 0);
    shop->health_btn = init_health_btn(res);
    shop->dream_stone = init_dream_stone_btn(res);
    init_coin(res, shop);
    return shop;
}
