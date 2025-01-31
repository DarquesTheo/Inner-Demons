/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** shop
*/

#ifndef SHOP_H_
    #define SHOP_H_

    #include "SFML/Graphics.h"
    #include "SFML/Window.h"
    #include "res.h"
    #include <stdlib.h>
    #include "button.h"
    #include "game.h"

    #define SHOPSIZE_X 900
    #define SHOPSIZE_Y 800
    #define SHOPPOS_X 100000 - SHOPSIZE_X / 2 + 50
    #define SHOPPOS_Y 100000 - SHOPSIZE_Y / 2

    #define COIN_TEXT_POS_X 100000 - 840
    #define COIN_TEXT_POS_Y 100000 - 380
    #define COIN_TEXT_SIZE 30
    #define COIN_OUTLINE_THICKNESS 1
    #define COIN_OUTLINE_COLOR sfBlack
    #define COIN_FILL_COLOR sfYellow

    #define COIN_LOGO_POS_X 100000 - 900
    #define COIN_LOGO_POS_Y 100000 - 385
    #define COIN_LOGO_SCALE 3

    // Health buy
    #define HEALTH_PRICE 50
    #define HEALTH_AMOUNT 1

/*  ------  ######  ------  */
/*  ------  STRUCT  ------  */
/*  ------  ######  ------  */

typedef struct shop_button_s {
    button_t *btn;
    sfText *text;
    sfSprite *icon;
    sfText *price;
} shop_button_t;

typedef struct shop_s {
    sfBool visible;
    sfRectangleShape *window;
    shop_button_t *health_btn;
    shop_button_t *dream_stone;
    sfSprite *coin_icon;
    sfText *coin_text;
} shop_t;

/*  ------  ########  ------  */
/*  ------  FUNCTION  ------  */
/*  ------  ########  ------  */

void sfrenderwindow_drawshop(sfRenderWindow *window, shop_t *shop);
shop_t *init_shop(res_t *res);
void shop_toggle(shop_t *shop, game_t *game);
void shop_refresh_coin(shop_t *shop, game_t *game);
void draw_coin(sfRenderWindow *window, shop_t *shop);

//free
void shop_destroy(shop_t *shop);

//game relative
void buy_health(game_t *game);
void open_dream_forge(game_t *game);
void shop_check_click(game_t *game);
void artefact_tryclose(game_t *game);
void shop_refresh_locked(shop_t *shop, game_t *game);

#endif /* !SHOP_H_ */
