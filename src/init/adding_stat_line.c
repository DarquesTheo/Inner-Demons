/*
** EPITECH PROJECT, 2024
** adding_stat_line.c
** File description:
** adding_stat_line
*/

#include "artefact.h"
#include "ui.h"

void add_normal_stat_line(game_t *game)
{
    add_stat_line(&game->ui->artefact->lines, 42, game->res);
}

void add_boss_stat_line(game_t *game, stat_type_t type)
{
    add_stat_line(&game->ui->artefact->lines, type, game->res);
}
