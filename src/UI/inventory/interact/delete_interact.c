/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** delete_slot_content
*/

#include "interact.h"
#include "ui.h"
#include "utils.h"
#include "player.h"
#include "item.h"

void delete_interact(game_t *game)
{
    weapon_t *weapon = NULL;

    if (game->ui == NULL)
        return;
    weapon = inventory_getslotcontent(game->ui->inventory,
        game->ui->interact->locked_slot);
    if (weapon == NULL)
        return;
    inventory_insertitem(game->ui->inventory, NULL,
        game->ui->interact->locked_slot);
    free_weapon(weapon);
}
