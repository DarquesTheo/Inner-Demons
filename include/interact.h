/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** inventory_interact
*/

#ifndef INVENTORY_INTERACT_H_
    #define INVENTORY_INTERACT_H_

    #include "button.h"
    #include "game.h"

    #define INTERACT_MENU_SIZE_X 120
    #define INTERACT_MENU_SIZE_Y 450

    #define E_TEXT_OFFSET_X 19
    #define E_TEXT_OFFSET_Y 26

    #define E_MAINHAND_OFFSET_X 10
    #define E_MAINHAND_OFFSET_Y E_TEXT_OFFSET_Y + 25
    #define E_MAINHAND_SIZE_X 100
    #define E_MAINHAND_SIZE_Y 75

    #define E_OFFHAND_OFFSET_Y 75 + E_MAINHAND_OFFSET_Y
    #define E_DELETE_OFFSET_Y 75 + E_OFFHAND_OFFSET_Y
    #define E_SELL_OFFSET_Y 75 + E_DELETE_OFFSET_Y
    #define E_MERGE_OFFSET_Y 75 + E_SELL_OFFSET_Y

    #define BLOCKED_BTN_COLOR 155, 155, 155, 255

    #define E_MAX_Y 100000 + 540

    #define INTERACT game->ui->interact
    #define LOCKED_POS INTERACT->locked_slot.x, INTERACT->locked_slot.y

    #define COIN_PER_SALE 5

typedef struct interact_menu_s {
    sfBool visible;
    sfBool locked;
    sfText *itemname;
    sfRectangleShape *background;
    button_t *EquipMainhand;
    button_t *EquipOffhand;
    button_t *sell;
    button_t *delete;
    button_t *merge;
    sfVector2i locked_slot;
} interact_t;

//function
void interact_menu_setpos(interact_t *menu, sfVector2f pos);
void interact_draw(sfRenderWindow *window, interact_t *menu, game_t *game);
void interact_event_hover(game_t *game);
void interact_event_clicked(game_t *game);
void interact_button_event_click(game_t *game);
void refresh_interact_name(game_t *game);
sfBool is_mouse_in_inventory(game_t *game);

//button action
void equip_mainhand(game_t *game);
void equip_offhand(game_t *game);
void delete_interact(game_t *game);
void sell(game_t *game);
void interact_try_sell(game_t *game);
void merge(game_t *game);
sfBool can_merge(game_t *game);

#endif /* !INVENTORY_INTERACT_H_ */
