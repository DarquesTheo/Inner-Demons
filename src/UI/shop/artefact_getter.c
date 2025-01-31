/*
** EPITECH PROJECT, 2024
** artefact_getter.c
** File description:
** artefact_getter
*/

#include "artefact.h"
#include "game.h"
#include "ui.h"
#include "utils.h"
#include <string.h>

void draw_lines_artefact(sfRenderWindow *window,
    ui_line_artefact_t *lines, game_t *game)
{
    sfVector2f text_pos = v2f(100000 - 1510 / 2, 100000 - 50);
    char str[10] = "level ";
    char *str_lvl = my_atoi(game->ui->artefact->level);

    strcat(str, str_lvl);
    sfText_setString(game->ui->artefact->text_level, str);
    sfText_setPosition(game->ui->artefact->text_level, text_pos);
    sfRenderWindow_drawText(window, game->ui->artefact->text_level, NULL);
    sfRenderWindow_drawSprite(window, game->ui->artefact->stat_table, NULL);
    for (; lines != NULL; lines = lines->next) {
        if (lines->unlocked)
            draw_lines_artefact2(window, lines);
        else
            sfRenderWindow_drawSprite(window, lines->unlock, NULL);
    }
    draw_lines_artefact3(window, game);
    free(str_lvl);
}

int get_max_range(stat_type_t type, artefact_t *artefact)
{
    int max = artefact->range->quality_max[type] +
        artefact->range->quality_incr[type] * 2 * (artefact->level - 1);

    if (max > artefact->range->quality_cap[type])
        max = artefact->range->quality_cap[type];
    return max;
}

int get_min_range(stat_type_t type, artefact_t *artefact)
{
    int min = artefact->range->quality_min[type] +
        artefact->range->quality_incr[type] * (artefact->level - 1);

    if (min > artefact->range->quality_cap[type])
        min = artefact->range->quality_cap[type];
    return min;
}

float get_multiplicator_stat(stat_type_t type, game_t *game)
{
    float multiplicator = 1;
    ui_line_artefact_t *list = game->ui->artefact->lines;

    for (; list != NULL; list = list->next) {
        if (list->type == type) {
            multiplicator += (float) list->quality / 100;
        }
    }
    return multiplicator;
}
