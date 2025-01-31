/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** ui
*/

#ifndef UI_H_
    #define UI_H_
    #include <SFML/Graphics.h>
    #include "inventory.h"
    #include "shop.h"
    #include "heart.h"
    #include "death.h"
    #include "artefact.h"
    #include "interact.h"
    #include "boss_bar.h"

typedef struct ui_s {
    sfView *view;
    inventory_t *inventory;
    shop_t *shop;
    heart_t *heart;
    death_menu_t *death_menu;
    artefact_t *artefact;
    interact_t *interact;
    ui_hp_boss_t *boss_bar;
} ui_t;

//init
ui_t *init_ui(res_t *res);

//functions

#endif /* !UI_H_ */
