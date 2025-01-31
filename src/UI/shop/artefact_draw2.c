/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** artefact_draw2
*/

#include "artefact.h"
#include "utils.h"
#include "keybinds.h"
#include "ui.h"
#include "vector.h"
#include "player.h"
#include <stdlib.h>
#include <string.h>

void draw_artefact_ui2(sfRenderWindow *window, artefact_t *node, game_t *game)
{
    char *str = malloc(sizeof(char) * 200);
    char *str_cost = my_atoi(5 * game->ui->artefact->level);

    sfRenderWindow_drawSprite(window, node->bg, NULL);
    draw_lines_artefact(window, node->lines, game);
    sfRenderWindow_drawSprite(window, node->sprite, NULL);
    sfRenderWindow_drawSprite(window, node->back, NULL);
    strcpy(str, "Roll Stat Cost : ");
    strcat(str, str_cost);
    free(str_cost);
    strcat(str, "\nRoll Quality Cost : ");
    str_cost = my_atoi(2 * game->ui->artefact->level);
    strcat(str, str_cost);
    free(str_cost);
    sfText_setString(node->text_roll_price, str);
    sfRenderWindow_drawText(window, node->text_roll_price, NULL);
    free(str);
}
