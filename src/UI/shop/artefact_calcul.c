/*
** EPITECH PROJECT, 2024
** artefact_calcul.c
** File description:
** calcul
*/

#include "artefact.h"
#include "utils.h"
#include "game.h"
#include "player.h"
#include "ui.h"
#include <string.h>
#include "const.h"

sfBool need_coin(game_t *game, int type, UNUSED ui_line_artefact_t *line)
{
    int coin = game->player->coin;

    if (type == 0) {
        if (coin >= 0)
            return sfFalse;
    }
    if (type == 1) {
        if (coin >= 5 * game->ui->artefact->level)
            return sfFalse;
    }
    if (type == 2) {
        if (coin >= 2 * game->ui->artefact->level)
            return sfFalse;
    }
    return sfTrue;
}

void remove_coin(game_t *game, int type, UNUSED ui_line_artefact_t *line)
{
    if (type == 0)
        player_gain_coin(game, -(0));
    if (type == 1)
        player_gain_coin(game, -5 * game->ui->artefact->level);
    if (type == 2)
        player_gain_coin(game, -2 * game->ui->artefact->level);
}

static void roll_stat_line2(ui_line_artefact_t *line)
{
    if (line->type == ATTACK_SPEED)
        sfText_setString(line->text_stat, "Attack speed");
    if (line->type == DAMAGE)
        sfText_setString(line->text_stat, "Damage");
    if (line->type == MOVEMENT_SPEED)
        sfText_setString(line->text_stat, "Movement speed");
    if (line->type == ACCURACY)
        sfText_setString(line->text_stat, "Accuracy");
    if (line->type == LUCK)
        sfText_setString(line->text_stat, "Luck");
    if (line->type == INTELLIGENCE)
        sfText_setString(line->text_stat, "Intelligence");
}

void roll_stat_line(ui_line_artefact_t *line)
{
    int random = rand() % 6;
    stat_type_t j = 0;

    for (int i = 0; i < random; i++) {
        if (j == line->type)
            j++;
        j++;
    }
    if (j == line->type)
        j = j + 1;
    j = j % 6;
    if (j == 0 && j == line->type)
        j = 1;
    line->type = j;
    line->unlocked = sfTrue;
    roll_stat_line2(line);
}

void roll_quality_line(ui_line_artefact_t *line, artefact_t *artefact)
{
    int min = get_min_range(line->type, artefact);
    int max = get_max_range(line->type, artefact);
    int percent;
    char *str;

    if (max > artefact->range->quality_cap[line->type])
        max = artefact->range->quality_cap[line->type];
    if (min > artefact->range->quality_cap[line->type])
        min = artefact->range->quality_cap[line->type];
    percent = (rand() % (max - min + 1)) + min;
    str = my_atoi(percent);
    line->quality = percent;
    strcat(str, "%");
    sfText_setString(line->text_percent, str);
    free(str);
}
