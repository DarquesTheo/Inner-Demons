/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** artifact_tryclose
*/

#include "game.h"
#include "ui.h"

void artefact_tryclose(game_t *game)
{
    if (game->ui->artefact->visible) {
        open_dream_forge(game);
        game->info->in_menu = 0;
    }
}
