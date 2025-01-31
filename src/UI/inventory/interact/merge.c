/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** merge
*/

#include "interact.h"
#include "game.h"
#include "inventory.h"
#include "ui.h"
#include "button.h"
#include "utils.h"
#include "player.h"
#include <string.h>

sfBool weapon_cmp(weapon_t *wp1, weapon_t *wp2)
{
    if (wp1 == NULL || wp2 == NULL)
        return sfFalse;
    if (wp1->lvl != wp2->lvl)
        return sfFalse;
    if (strcmp(wp1->name, wp2->name) != 0)
        return sfFalse;
    return sfTrue;
}

static sfVector2i find_weapon_in_line(game_t *game, weapon_t *weapon,
    int i)
{
    inventory_t *inv = game->ui->inventory;

    for (int j = 0; j < inv->size_x; j++) {
        if (inv->inv[i][j] == NULL)
            continue;
        if (weapon_cmp(weapon, inv->inv[i][j]->content))
            return (sfVector2i){j, i};
    }
    return (sfVector2i){-1, -1};
}

static sfVector2i find_same_weapon(game_t *game, weapon_t *weapon)
{
    inventory_t *inv = game->ui->inventory;
    sfVector2i wppos = (sfVector2i){-1, -1};

    for (int i = 0; i < inv->size_y; i++) {
        wppos = find_weapon_in_line(game, weapon, i);
        if (wppos.x != -1 && wppos.y != -1)
            return wppos;
    }
    return (sfVector2i){-1, -1};
}

sfBool can_merge(game_t *game)
{
    sfVector2i poswp1 = {-1, -1};
    sfVector2i poswp2 = {-1, -1};
    weapon_t *wp[3] = {NULL};
    inventory_t *inv = NULL;

    if (game->ui == NULL)
        return sfFalse;
    inv = game->ui->inventory;
    wp[0] = inventory_getslotcontent(inv, (sfVector2i){LOCKED_POS});
    inventory_insertitem(inv, NULL, (sfVector2i){LOCKED_POS});
    poswp1 = find_same_weapon(game, wp[0]);
    wp[1] = inventory_getslotcontent(inv, poswp1);
    inventory_insertitem(inv, NULL, poswp1);
    poswp2 = find_same_weapon(game, wp[0]);
    wp[2] = inventory_getslotcontent(inv, poswp2);
    inventory_insertitem(inv, wp[1], poswp1);
    inventory_insertitem(inv, wp[0], (sfVector2i){LOCKED_POS});
    return (wp[1] != NULL && wp[2] != NULL) ? sfTrue : sfFalse;
}

void merge(game_t *game)
{
    sfVector2i poswp1 = {-1, -1};
    sfVector2i poswp2 = {-1, -1};
    weapon_t *wp[3] = {NULL};
    inventory_t *inv = NULL;

    if (game->ui == NULL)
        return;
    if (!can_merge(game))
        return;
    inv = game->ui->inventory;
    wp[0] = inventory_getslotcontent(inv, (sfVector2i){LOCKED_POS});
    inventory_insertitem(inv, NULL, (sfVector2i){LOCKED_POS});
    poswp1 = find_same_weapon(game, wp[0]);
    wp[1] = inventory_getslotcontent(inv, poswp1);
    inventory_insertitem(inv, NULL, poswp1);
    poswp2 = find_same_weapon(game, wp[0]);
    wp[2] = inventory_getslotcontent(inv, poswp2);
    inventory_insertitem(inv, NULL, poswp2);
    wp[0]->lvl += 1;
    inventory_insertitem(inv, wp[0], (sfVector2i){LOCKED_POS});
}
