/*
** EPITECH PROJECT, 2024
** expe_bar
** File description:
** exp_bar_handle
*/

#include "game.h"
#include "ui.h"
#include "artefact.h"
#include "utils.h"
#include "system.h"
#include "boss_bar.h"
#include "map.h"
#include "enemies.h"
#include <string.h>
#include "sound_manager.h"

static const char *boss_names[4] = {"Anger", "Anxiety",
    "Despair", "Trauma"};

void get_exp_from_mob(game_t *game, mob_t *mob)
{
    artefact_t *artefact = game->ui->artefact;
    int value;

    if (game->system->statut == COMBAT_BOSS && mob->type < BOSS1)
        return;
    if (mob->type < BOSS1)
        value = 100;
    else
        value = 1000;
    artefact->cur_exp += value * get_multiplicator_stat(INTELLIGENCE, game);
    if (artefact->cur_exp >= artefact->max_exp) {
        artefact->cur_exp = artefact->cur_exp % artefact->max_exp;
        artefact->max_exp += 200 * artefact->level;
        artefact->level += 1;
        play_sound(game, "artefact_lvl_up", 1);
    }
}

void draw_exp_bar(game_t *game)
{
    artefact_t *artefact = game->ui->artefact;
    int ratio = (artefact->cur_exp * MAX_EXP_X) /
        artefact->max_exp;

    sfRectangleShape_setSize(artefact->exp_bar, v2f(ratio, 30));
    sfRenderWindow_drawRectangleShape(game->window,
        game->ui->artefact->exp_bar, NULL);
    sfRenderWindow_drawSprite(game->window,
        game->ui->artefact->exp_bar_sprite, NULL);
}

ui_hp_boss_t *init_ui_boss_bar(res_t *res)
{
    ui_hp_boss_t *new = malloc(sizeof(ui_hp_boss_t));

    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, res->artefact->hp_bar, sfFalse);
    sfSprite_setPosition(new->sprite,
        v2f(100000 - 960 / 2, 100000 - 1040 / 2));
    sfSprite_setScale(new->sprite, v2f(1, 1));
    new->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(new->rect, v2f(100000 - 956 / 2,
        100000 - 1030 / 2));
    sfRectangleShape_setFillColor(new->rect, sfRed);
    sfRectangleShape_setOutlineColor(new->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(new->rect, 2);
    new->name = sfText_create();
    sfText_setCharacterSize(new->name, 40);
    sfText_setFont(new->name, res->fonts->dialogue_font);
    return new;
}

static void draw_boss_name(game_t *game)
{
    const char *name = boss_names[game->system->biome];

    sfText_setString(game->ui->boss_bar->name, name);
    sfText_setPosition(game->ui->boss_bar->name,
        v2f(100000 - sfText_getGlobalBounds(game->ui->boss_bar->name).width /
        2, 100000 - 960 / 2));
    sfRenderWindow_drawText(game->window, game->ui->boss_bar->name, NULL);
}

void draw_boss_bar(game_t *game)
{
    int act = 0;
    int max = 0;

    if (game->system->statut == COMBAT_BOSS) {
        for (mob_t *mob = game->map->mobs; mob != NULL; mob = mob->next) {
            act += mob->type >= BOSS1 ? mob->stats->cur_hp : 0;
            max += mob->type >= BOSS1 ? mob->stats->max_hp : 0;
        }
        if (max == 0)
            return;
        if (act < 0)
            act = 0;
        sfRectangleShape_setSize(game->ui->boss_bar->rect,
            v2f(act * MAX_HP_X / max, 26));
        sfRenderWindow_drawRectangleShape(game->window,
            game->ui->boss_bar->rect, NULL);
        sfRenderWindow_drawSprite(game->window,
            game->ui->boss_bar->sprite, NULL);
        draw_boss_name(game);
    }
}
