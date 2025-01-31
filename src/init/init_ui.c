/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_ui
*/

#include "ui.h"
#include <stdlib.h>
#include "inventory.h"
#include "heart.h"
#include "artefact.h"
#include "player.h"
#include "boss_bar.h"

ui_t *init_ui(res_t *res)
{
    ui_t *ui = malloc(sizeof(ui_t));

    ui->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfView_setCenter(ui->view, (sfVector2f){100000, 100000});
    ui->inventory = inventory_create((sfVector2i) {5, 10},
        (sfVector2f){100610, 100000 - 270}, res);
    inventory_seticongetter(ui->inventory, (void *)&get_weapon_icon);
    ui->shop = init_shop(res);
    ui->heart = init_heart(res, DEFAULT_MAX_HEALTH);
    ui->death_menu = init_death_menu(res);
    ui->artefact = init_artefact_struct(res);
    ui->interact = init_interact_menu(res);
    ui->boss_bar = init_ui_boss_bar(res);
    return ui;
}
