/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** open_dream_forge
*/

#include "game.h"
#include "shop.h"
#include "ui.h"

void open_dream_forge(game_t *game)
{
    game->ui->artefact->visible = !game->ui->artefact->visible;
    if (game->ui->artefact->visible) {
        game->ui->shop->visible = sfFalse;
        game->ui->inventory->active = sfFalse;
    } else {
        game->ui->shop->visible = sfTrue;
        game->ui->inventory->active = sfTrue;
    }
}
