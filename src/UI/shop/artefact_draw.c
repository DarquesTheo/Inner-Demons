/*
** EPITECH PROJECT, 2024
** artefact_draw.c
** File description:
** artefact drawing
*/

#include "artefact.h"
#include "utils.h"
#include "keybinds.h"
#include "ui.h"
#include "vector.h"
#include "player.h"
#include <string.h>

static void check_button_state_artefact3
(ui_line_artefact_t *line, sfVector2f pos, sfBool click, game_t *game)
{
    sfFloatRect hitbox;

    hitbox = sfSprite_getGlobalBounds(line->roll_quality);
    if (sfFloatRect_contains(&hitbox, pos.x, pos.y) && !click)
        sfSprite_setTextureRect(line->roll_quality,
            (sfIntRect) {790, 0, 790, 343});
    if ((sfFloatRect_contains(&hitbox, pos.x, pos.y) && click) ||
        need_coin(game, 2, line))
        sfSprite_setTextureRect(line->roll_quality,
            (sfIntRect) {1580, 0, 790, 343});
}

static void check_button_state_artefact2
(ui_line_artefact_t *line, sfVector2f pos, sfBool click, game_t *game)
{
    sfFloatRect hitbox;

    if (!line->unlocked)
        return;
    sfSprite_setTextureRect(line->roll_stat, (sfIntRect) {0, 0, 790, 343});
    sfSprite_setTextureRect(line->roll_quality, (sfIntRect) {0, 0, 790, 343});
    hitbox = sfSprite_getGlobalBounds(line->roll_stat);
    if (sfFloatRect_contains(&hitbox, pos.x, pos.y) && !click)
        sfSprite_setTextureRect(line->roll_stat,
            (sfIntRect) {790, 0, 790, 343});
    if ((sfFloatRect_contains(&hitbox, pos.x, pos.y) && click) ||
        need_coin(game, 1, line))
        sfSprite_setTextureRect(line->roll_stat,
            (sfIntRect) {1580, 0, 790, 343});
    check_button_state_artefact3(line, pos, click, game);
}

static void check_button_state_artefact(artefact_t *node, game_t *game,
    sfBool click)
{
    sfFloatRect hitbox;
    sfVector2f pos = game->info->local_mouse_pos;
    sfVector2u window_size = sfRenderWindow_getSize(game->window);

    pos.x = 100000 + pos.x * 1920 / window_size.x - 960;
    pos.y = 100000 + pos.y * 1080 / window_size.y - 540;
    for (ui_line_artefact_t *lines = node->lines; lines != NULL;
        lines = lines->next) {
        hitbox = sfSprite_getGlobalBounds(lines->unlock);
        sfSprite_setTextureRect(lines->unlock, (sfIntRect) {0, 0, 790, 343});
        if (!lines->unlocked && sfFloatRect_contains(&hitbox, pos.x, pos.y)
            && !click)
            sfSprite_setTextureRect(lines->unlock,
                (sfIntRect) {790, 0, 790, 343});
        if ((!lines->unlocked && sfFloatRect_contains(&hitbox, pos.x, pos.y)
            && click) || need_coin(game, 0, lines))
            sfSprite_setTextureRect(lines->unlock,
                (sfIntRect) {1580, 0, 790, 343});
        check_button_state_artefact2(lines, pos, click, game);
    }
}

static void check_button_artefact2
(ui_line_artefact_t *line, game_t *game, sfVector2f pos)
{
    sfFloatRect hitbox;

    hitbox = sfSprite_getGlobalBounds(line->roll_stat);
    if (sfFloatRect_contains(&hitbox, pos.x, pos.y) && line->type < 6 &&
        !need_coin(game, 1, line)) {
        remove_coin(game, 1, line);
        roll_stat_line(line);
        roll_quality_line(line, game->ui->artefact);
    }
    hitbox = sfSprite_getGlobalBounds(line->roll_quality);
    if (sfFloatRect_contains(&hitbox, pos.x, pos.y) &&
        !need_coin(game, 2, line)) {
        remove_coin(game, 2, line);
        roll_quality_line(line, game->ui->artefact);
    }
}

static void check_button_artefact3
(ui_line_artefact_t *line, game_t *game, sfVector2f pos)
{
    if (line->unlocked)
        check_button_artefact2(line, game, pos);
}

sfBool check_button_artefact(artefact_t *node, game_t *game)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(node->back);
    sfVector2f pos = game->info->local_mouse_pos;
    sfVector2u window_size = sfRenderWindow_getSize(game->window);

    pos.x = 100000 + pos.x * 1920 / window_size.x - 960;
    pos.y = 100000 + pos.y * 1080 / window_size.y - 540;
    if (sfFloatRect_contains(&hitbox, pos.x, pos.y))
        open_dream_forge(game);
    for (ui_line_artefact_t *lines = node->lines; lines != NULL;
        lines = lines->next) {
        hitbox = sfSprite_getGlobalBounds(lines->unlock);
        if (!lines->unlocked && sfFloatRect_contains(&hitbox, pos.x, pos.y) &&
            !need_coin(game, 0, lines)) {
            roll_stat_line(lines);
            remove_coin(game, 0, lines);
            roll_quality_line(lines, game->ui->artefact);
        }
        check_button_artefact3(lines, game, pos);
    }
    return sfTrue;
}

void check_back_button_artefact(artefact_t *node, game_t *game)
{
    sfFloatRect hitbox;
    sfVector2f pos = game->info->local_mouse_pos;
    sfVector2u window_size = sfRenderWindow_getSize(game->window);

    pos.x = 100000 + pos.x * 1920 / window_size.x - 960;
    pos.y = 100000 + pos.y * 1080 / window_size.y - 540;
    hitbox = sfSprite_getGlobalBounds(node->back);
    if (sfFloatRect_contains(&hitbox, pos.x, pos.y))
        sfSprite_setTextureRect(node->back,
            (sfIntRect) {790, 0, 790, 343});
    else
        sfSprite_setTextureRect(node->back,
            (sfIntRect) {0, 0, 790, 343});
}

void draw_lines_artefact2(sfRenderWindow *window, ui_line_artefact_t *line)
{
    sfRenderWindow_drawText(window, line->text_percent, NULL);
    if (line->type >= DODGE)
        sfText_setColor(line->text_stat, sfYellow);
    sfRenderWindow_drawText(window, line->text_stat, NULL);
    sfRenderWindow_drawSprite(window, line->roll_quality, NULL);
    if (line->type < DODGE)
        sfRenderWindow_drawSprite(window, line->roll_stat, NULL);
}

void draw_lines_artefact3(sfRenderWindow *window, game_t *game)
{
    range_artefact_t *range = game->ui->artefact->range;
    char *max;
    char *min;
    char *str;

    for (int i = 0; i < 10; i++) {
        str = malloc(sizeof(char) * 150);
        strcpy(str, range->stat_str[i]);
        max = my_atoi(get_max_range(i, game->ui->artefact));
        min = my_atoi(get_min_range(i, game->ui->artefact));
        strcat(str, min);
        strcat(str, " - ");
        strcat(strcat(str, max), "]");
        sfText_setString(range->text[i], str);
        sfText_setPosition(range->text[i], v2f(99130, 100055 + 36 * i));
        sfRenderWindow_drawText(window, range->text[i], NULL);
        free(str);
        free(min);
        free(max);
    }
}

void draw_artefact_ui(sfRenderWindow *window, artefact_t *node, game_t *game)
{
    if (!node->visible)
        return;
    place_lines(node->lines);
    if (game->info->mouse->left_click == sfTrue && !node->on_click) {
        node->on_click = check_button_artefact(node, game);
    } else if (game->info->mouse->left_click == sfFalse)
        node->on_click = sfFalse;
    check_back_button_artefact(node, game);
    check_button_state_artefact(node, game, game->info->mouse->left_click);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(node->clock)) >= 100) {
        node->rect.left += 150;
        if (node->rect.left >= 4650)
            node->rect.left = 0;
        sfSprite_setTextureRect(node->sprite, node->rect);
        sfClock_restart(node->clock);
    }
    draw_artefact_ui2(window, node, game);
}
